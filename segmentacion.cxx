#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <queue>
using namespace cv;
struct point
{
    int i;
    int j;
};

typedef std::queue<point> Queue;
Mat crecimiento_regiones(Mat image, Queue frente);
void Crecimiento_Regiones_aux(Mat *image, Mat *reg, int i, int j, bool **est);
float desviacion(Mat *image, Queue neighbours);
Queue getNeighbours(Mat *image, point p);
void print(Queue c);
bool aceptacion(Mat *image, int i, int j);
float promedio(Mat *image, Queue neighbours);
float criterio;

int main(int argc, char const *argv[])
{

    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << std::endl;
        return (-1);
    } // fi

    // Review given command line arguments
    std::cout << "-------------------------" << std::endl;
    for (int a = 0; a < argc; a++)
        std::cout << argv[a] << std::endl;
    std::cout << "-------------------------" << std::endl;

    // Read an image
    Mat image;
    image = imread(argv[1], 1);

    if (!image.data)
    {
        std::cerr << "Error: No image data" << std::endl;
        return (-1);
    }
    criterio = atof(argv[2]);
    /*MatIterator_<Vec3b> it,end;
    it = image.begin<Vec3b>();
    end = image.end<Vec3b>();

    for (; it != end; it++)
    {
        std::cout<<"R: "<<(unsigned int)(*it)[2]<<"G: "<<(unsigned int)(*it)[1]<<"B: "<<(unsigned int)(*it)[0]<<std::endl;
    }*/
    /*for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
          std::cout<<"R: "<<(unsigned int)(image.at<Vec3b>(i,j))[2]<<"G: "<<(unsigned int)(image.at<Vec3b>(i,j))[1]<<"B: "<<(unsigned int)(image.at<Vec3b>(i,j))[0]<<std::endl;  
        }
    }*/
    //std::cout<<"c "<<image.cols <<" r"<<image.rows<<std::endl;
    point p;
    p.i = image.rows / 2;
    p.j = image.cols / 2;
    Queue cola;
    cola.push(p);
    Mat final = crecimiento_regiones(image, cola);

    imwrite("resultado.png", final);
}
Mat crecimiento_regiones(Mat image, Queue frente)
{
    Mat result = Mat::zeros(image.rows, image.cols, image.type());
    Queue cola;
    bool **est = new bool *[image.rows];
    for (int i = 0; i < image.rows; i++)
    {
        est[i] = new bool[image.cols];
    }
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            est[i][j] = false;
        }
    }

    while (!frente.empty())
    {
        point p = frente.front();
        cola.push(frente.front());
        frente.pop();
    }
    while (!cola.empty())
    {
        
        float des1, des2;
        point p = cola.front();
        cola.pop();
        result.at<Vec3b>(p.i, p.j) = image.at<Vec3b>(p.i, p.j);
        //result.at<Vec3b>(p.i, p.j) = {255,255,255};
        if (est[p.i][p.j] == false)
        {
            est[p.i][p.j] = true;
            //std::cout<<"while "<< cola.size()<<std::endl;
        }
        else
        {
            continue;
        }
        //deviation

        Queue c = getNeighbours(&image, p);
        //print(c);
        des1 = desviacion(&image, c);

        //get neighbours
        while (!c.empty())
        {
            
            point neigh = c.front();
            Queue neighbours = getNeighbours(&image, neigh);
            des2 = desviacion(&image, neighbours);
            //std::cout << abs(des1 - des2) << std::endl;
            if (abs(des1 - des2) < criterio )
            {
                //std::cout<<"while2"<<std::endl;
                cola.push(c.front());
            }
            c.pop();
        }
        //std::cout<<"while2end"<<std::endl;
    }
    std::cout << "whileend" << std::endl;

    return result;
}
void print(Queue c){
    while (!c.empty())
    {
        point p = c.front();
        c.pop();
        std::cout << "i: " << p.i << " j: " << p.j << std::endl;
    }
    
}
bool aceptacion(Mat *image, int i, int j)
{
    //std::cout << "i: " << i << " j: " << j << std::endl;
    if (i <= 0 || j <= 0)
    {
        return false;
    }
    if (i >= image->rows - 1 || j >= image->cols - 1)
    {
        return false;
    }
    return true;
}

Queue getNeighbours(Mat *image, point p)
{
    Queue cola;
    point p1;
    p1.i = p.i;
    p1.j = p.j + 1;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //right

    p1.i = p.i;
    p1.j = p.j - 1;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //left

    p1.i = p.i + 1;
    p1.j = p.j;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //down

    p1.i = p.i - 1;
    p1.j = p.j;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //up

    p1.i = p.i - 1;
    p1.j = p.j + 1;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //up right

    p1.i = p.i - 1;
    p1.j = p.j - 1;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //up left

    p1.i = p.i + 1;
    p1.j = p.j + 1;
    if(aceptacion(image, p1.i, p1.j))
        cola.push(p1); //down right

    p1.i = p.i + 1;
    p1.j = p.j - 1;
    if (aceptacion(image, p1.i, p1.j))
        cola.push(p1); //down left
    return cola;
}
float promedio(Mat *image, Queue neighbours)
{
    float tam = neighbours.size();
    float prom= 0;
    while (!neighbours.empty())
    {
       
        point p = neighbours.front();
        neighbours.pop();
        for (int i = 0; i < 3; i++)
        {
            prom += (int)image->at<Vec3b>(p.i, p.j)[i];
        }
    }
    return prom / tam;
}
float desviacion(Mat *image, Queue neighbours)
{
    float des = 0;
    float tam = neighbours.size();
    float prom = promedio(image, neighbours);
    while (!neighbours.empty())
    {
        point p = neighbours.front();
        neighbours.pop();
        for (int i = 0; i < 3; i++)
        {
            des += (float)pow((int)image->at<Vec3b>(p.i, p.j)[i] - prom, 2);
        }
    }
    return sqrt(des / (tam * 3));
}
