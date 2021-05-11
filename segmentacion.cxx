#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <queue>
using namespace cv;
struct point
{
    int i;
    int j;
};
typedef std::vector<Point2f> Vector;
typedef std::queue<point> Queue;
void crecimiento_regiones(Mat image, Queue frente, Mat *etiquetada, Mat *segmentada);
float desviacion(Mat *image, Queue neighbours);
Queue getNeighbours(Mat *image, point p);
void print(Queue c);
bool aceptacion(Mat *image, int i, int j);
float promedio(Mat *image, Queue neighbours);
Queue semillas(Mat image, int cantidad);
bool similaridad(Mat *image, Queue p1, Queue p2);
float mayorContraste(Mat *image, Queue neighbours);
float criterio;
int vecinos;
int tipo;
int main(int argc, char const *argv[])
{

    if (argc < 2)
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
    else
    {
        std::cout << "Informacion de la imagen" << std::endl
                  << "-----Tamaño------\n"
                  << "Ancho(columnas): " << image.cols << std::endl
                  << "Alto(filas): " << image.rows << std::endl;
    }

    //menu
    std::cout << "------Menu------" << std::endl
              << std::endl;
    std::cout << "indique la fomra de meida de similaridad "
              << "Desviacion(1)"
              << " Promedio(2)"
              << " contraste(3) : ";
    std::cin >> tipo;
    std::cout << "inidque criterio de aceptacion(valor flotante): ";
    std::cin >> criterio;
    std::cout << "Cantidad de vecinos (4 o 8) :";
    int vecinos;
    std::cin >> vecinos;
    
    std::cout << "semillas automaticas si(1)/no(0): ";
    int automaticas;
    std::cin >> automaticas;
    int noSemillas;
    std::cout << "inidque numero de semillas: ";
    std::cin >> noSemillas;
    Queue cola;
    if (automaticas == 1)
        cola = semillas(image, noSemillas);
    else
    {
        for (int i = 0; i < noSemillas; i++)
        {
            point p;
            std::cout << "digite el eje x :";
            std::cin >> p.j;
            std::cout << "digite el eje y :";
            std::cin >> p.i;
            cola.push(p);
        }
    }
    Mat etiquetada = Mat::zeros(image.rows, image.cols, image.type());
    Mat segmentada = Mat::zeros(image.rows, image.cols, image.type());
    crecimiento_regiones(image, cola, &etiquetada, &segmentada);

    imwrite("etiquetada.png", etiquetada);
    imwrite("segmentada.png", segmentada);
}
Queue semillas(Mat image, int cantidad)
{
    srand(time(NULL));
    Queue seads;
    for (int i = 0; i < cantidad; i++)
    {
        point p;

        p.i = rand() % image.rows;
        p.j = rand() % image.cols;
        /*
        p.i = image.rows / 2;
        p.j = image.cols / 2;*/
        seads.push(p);
    }
    return seads;
}

void crecimiento_regiones(Mat image, Queue frente, Mat *etiquetada, Mat *segmentada)
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
        segmentada->at<Vec3b>(p.i, p.j) = image.at<Vec3b>(p.i, p.j); //apllay color
        etiquetada->at<Vec3b>(p.i, p.j) = {255, 255, 255};
        if (est[p.i][p.j] == false)
        {
            est[p.i][p.j] = true;
        }
        else
        {
            continue;
        }

        Queue c = getNeighbours(&image, p);

        //des1 = desviacion(&image, c);

        //get neighbours
        while (!c.empty())
        {

            point neigh = c.front();
            Queue neighbours = getNeighbours(&image, neigh);
            //des2 = desviacion(&image, neighbours);
            //std::cout << abs(des1 - des2) << std::endl;
            if (similaridad(&image, c, neighbours))
            {
                cola.push(c.front());
            }
            c.pop();
        }
    }
}
bool similaridad(Mat *image, Queue p1, Queue p2)
{
    if (tipo == 1) //desviacion estandar
        return (abs(desviacion(image, p1) - desviacion(image, p2)) <= criterio);
    if (tipo == 2)
        return (abs(promedio(image, p1) - promedio(image, p2)) <= criterio);
    //std::cout << abs(mayorContraste(image, p1) - mayorContraste(image, p2)) << std::endl;
    return (abs(mayorContraste(image, p1) - mayorContraste(image, p2)) <= criterio);
}
float mayorContraste(Mat *image, Queue neighbours)
{
    float mayorR = 0;
    float mayorG = 0;
    float mayorB = 0;

    while (!neighbours.empty())
    {
        point p = neighbours.front();
        neighbours.pop();
        if (image->at<Vec3b>(p.i, p.j)[0] > mayorB || image->at<Vec3b>(p.i, p.j)[1] > mayorG || image->at<Vec3b>(p.i, p.j)[2] > mayorR)
        {
            mayorB = image->at<Vec3b>(p.i, p.j)[0];
            mayorG = image->at<Vec3b>(p.i, p.j)[1];
            mayorR = image->at<Vec3b>(p.i, p.j)[2];
        }
    }
    if (mayorB >= mayorG && mayorB >= mayorR)
        return mayorB;
    if (mayorG > mayorB && mayorG > mayorR)
        return mayorG;
    return mayorR;
}
void print(Queue c)
{
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
    if (vecinos == 8)
    {
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
        if (aceptacion(image, p1.i, p1.j))
            cola.push(p1); //down right

        p1.i = p.i + 1;
        p1.j = p.j - 1;
        if (aceptacion(image, p1.i, p1.j))
            cola.push(p1); //down left
    }
    return cola;
}
float promedio(Mat *image, Queue neighbours)
{
    float tam = neighbours.size();
    float prom = 0;
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
