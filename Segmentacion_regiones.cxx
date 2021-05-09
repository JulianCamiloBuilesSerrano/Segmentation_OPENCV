#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace cv;
Mat crecimiento_regiones(Mat image);
void Crecimiento_Regiones_aux(Mat *image, Mat *reg, int i, int j, bool **est);
bool evaluacion_pixel(float punto1, float punto2);
float desviacion(Mat *image, int i, int j);
bool verificar(Mat *image, int i, int j);
float criterio = 3;
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
    Mat final = crecimiento_regiones(image);

    imwrite("resultado.png", final);
}
Mat crecimiento_regiones(Mat image)
{
    Mat reg = Mat::ones(image.rows, image.cols, image.type());
    //Mat est = Mat::zeros(image.rows, image.cols, image.type());
    bool **est = new bool *[image.rows];
    for (int i = 0; i < image.rows; i++)
    {
        est[i] = new bool[image.cols];
    }
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            est[i][j] = 0;
            //std::cout << est[i][j]<<std::endl;
        }
    }

    Crecimiento_Regiones_aux(&image, &reg, (int)image.rows / 2, (int)image.cols / 2, est);
    return reg;
}
float desviacion(Mat *image, int i, int j)
{
    float var;
    int arr[] = {
        (int)image->at<Vec3b>(i, j)[0],
        (int)image->at<Vec3b>(i + 1, j)[0],
        (int)image->at<Vec3b>(i - 1, j)[0],
        (int)image->at<Vec3b>(i, j + 1)[0],
        (int)image->at<Vec3b>(i, j - 1)[0],
        (int)image->at<Vec3b>(i + 1, j + 1)[0],
        (int)image->at<Vec3b>(i + 1, j - 1)[0],
        (int)image->at<Vec3b>(i - 1, j - 1)[0],
        (int)image->at<Vec3b>(i - 1, j + 1)[0],
        (int)image->at<Vec3b>(i, j)[1],
        (int)image->at<Vec3b>(i + 1, j)[1],
        (int)image->at<Vec3b>(i - 1, j)[1],
        (int)image->at<Vec3b>(i, j + 1)[1],
        (int)image->at<Vec3b>(i, j - 1)[1],
        (int)image->at<Vec3b>(i + 1, j + 1)[1],
        (int)image->at<Vec3b>(i + 1, j - 1)[1],
        (int)image->at<Vec3b>(i - 1, j - 1)[1],
        (int)image->at<Vec3b>(i - 1, j + 1)[1],
        (int)image->at<Vec3b>(i, j)[2],
        (int)image->at<Vec3b>(i + 1, j)[2],
        (int)image->at<Vec3b>(i - 1, j)[2],
        (int)image->at<Vec3b>(i, j + 1)[2],
        (int)image->at<Vec3b>(i, j - 1)[2],
        (int)image->at<Vec3b>(i + 1, j + 1)[2],
        (int)image->at<Vec3b>(i + 1, j - 1)[2],
        (int)image->at<Vec3b>(i - 1, j - 1)[2],
        (int)image->at<Vec3b>(i - 1, j + 1)[2]};
        
    float prom = 0;
    for (int g = 0; g < 27; g++)
    {
        prom += arr[g];
    }
    prom = prom / 27;
    float num = 0;
    for (int g = 0; g < 27; g++)
    {
        num += (float)pow(arr[g] - prom, 2);
    }

    return sqrt((float)num / 27);
    //var = num / 27;
    //std::cout<<var[k]<<std::endl;

    
}

bool verificar(Mat *image, int i, int j){
    if(i<0 || j< 0){
        return false;
    }
    if(i > image->rows - 1 || j > image->cols - 1){
        return false;
    }
    return true;
}
void Crecimiento_Regiones_aux(Mat *image, Mat *reg, int i, int j, bool **est)
{
    //std::cout<< " i "<< i << " j "<<j<<" Cols "<<image->cols <<" rows " <<image->rows<<std::endl;
    //std::cout<< est[i][j]<< std::endl;
    if (verificar(image, i, j) && est[i][j] == 0)
    {
        //calculate de var for the 3 chanels

        //std::cout<<est->at<Vec3b>(i, j)<<std::endl;
        est[i][j] = 1;
        reg->at<Vec3b>(i, j) = image->at<Vec3b>(i, j);
        //reg->at<Vec3b>(i, j) = {255, 255, 255};
        float var = desviacion(image, i, j);

        //evaluating near pixels
        //right
        if (evaluacion_pixel(var, desviacion(image, i, j + 1)))
        {
            //std::cout<< " i "<< i << " j "<< j<< " j+1 "<<j+1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i, j + 1, est);
        }
        else if(verificar(image, i, j+1))
        {
            reg->at<Vec3b>(i, j + 1)[0] = 0;
            reg->at<Vec3b>(i, j + 1)[1] = 0;
            reg->at<Vec3b>(i, j + 1)[2] = 0;
        }
        //left
        if (evaluacion_pixel(var, desviacion(image, i, j - 1)))
        {
            //std::cout<< " i "<< i << " j "<< j<< " j-1 "<<j-1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i, j - 1, est);
        }
        else if(verificar(image, i, j-1))
        {
            reg->at<Vec3b>(i, j - 1)[0] = 0;
            reg->at<Vec3b>(i, j - 1)[1] = 0;
            reg->at<Vec3b>(i, j - 1)[2] = 0;
        }

        //up
        if (evaluacion_pixel(var , desviacion(image, i-1, j )))
        {
            //std::cout<< " i "<< i << " j "<< j<< " i-1 "<<i-1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i - 1, j, est);
        }
        else
        {
            reg->at<Vec3b>(i - 1, j)[0] = 0;
            reg->at<Vec3b>(i - 1, j)[1] = 0;
            reg->at<Vec3b>(i - 1, j)[2] = 0;
        } 

        //down
        if (evaluacion_pixel(var, desviacion(image, i + 1, j)))
        {
            //std::cout<< " i "<< i << " j "<< j<< " i+1 "<<i+1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i + 1, j, est);
        }
        else if(verificar(image, i + 1, j))
        {
            reg->at<Vec3b>(i + 1, j)[0] = 0;
            reg->at<Vec3b>(i + 1, j)[1] = 0;
            reg->at<Vec3b>(i + 1, j)[2] = 0;
        }
        /*//up right
        if (evaluacion_pixel(var , desviacion(image, i-1, j + 1)))
        {
            //std::cout<< " i "<< i << " j "<< j<< " i-1 "<<i-1 << " j+1 "<<j+1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i - 1, j + 1, est);
        }
        else
        {
            reg->at<Vec3b>(i - 1, j + 1)[0] = 0;
            reg->at<Vec3b>(i - 1, j + 1)[1] = 0;
            reg->at<Vec3b>(i - 1, j + 1)[2] = 0;
        }

        //up left
        if (evaluacion_pixel(var ,desviacion(image, i-1, j - 1)))
        {
            //std::cout<< " i "<< i << " j "<< j<< " i-1 "<<i-1 << " j-1 "<<j-1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i - 1, j - 1, est);
        }
        else
        {
            reg->at<Vec3b>(i - 1, j - 1)[0] = 0;
            reg->at<Vec3b>(i - 1, j - 1)[1] = 0;
            reg->at<Vec3b>(i - 1, j - 1)[2] = 0;
        }
        //down right
        if (evaluacion_pixel(var , desviacion(image, i+1, j + 1)))
        {
            //std::cout<< " i "<< i << " j "<< j<< " i+1 "<<i+1 << " j+1 "<<j+1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i + 1, j + 1, est);
        }
        else
        {
            reg->at<Vec3b>(i + 1, j + 1)[0] = 0;
            reg->at<Vec3b>(i + 1, j + 1)[1] = 0;
            reg->at<Vec3b>(i + 1, j + 1)[2] = 0;
        }
        //down left
        if (evaluacion_pixel(var , desviacion(image, i+1, j - 1)))
        {
            //std:: << " i "<< i << " j "<< j<< " i+1 "<<i+1 << " j-1 "<<j-1<< std::endl;
            Crecimiento_Regiones_aux(image, reg, i + 1, j - 1, est);
        }
        else
        {
            reg->at<Vec3b>(i + 1, j - 1)[0] = 0;
            reg->at<Vec3b>(i + 1, j - 1)[1] = 0;
            reg->at<Vec3b>(i + 1, j - 1)[2] = 0;
        } */
    }else{
       // std::cout<<"LESE"<<std::endl;
    }
    return;
}

bool evaluacion_pixel(float punto1, float punto2)
{
    //std::cout<<punto1-punto2<<std::endl;
    if (abs(punto1 - punto2) <= criterio)
    {
        return true;
    }
    return false;
}
