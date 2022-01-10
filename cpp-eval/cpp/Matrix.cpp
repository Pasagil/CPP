#include "Matrix.h"
#include <iostream>

Matrix::Matrix(std::vector<std::vector<float>> cols)      // from a vector of vectors
{
    content = cols;
    shape = std::make_pair(content.size(), content[1].size());
}

Matrix::Matrix(int lines, int cols, float value)
{
    content = {};
    for (int i = 0 ; i<lines ; i++) {
        content.push_back (std::vector<float> (cols, value) );   
    }
    shape = std::make_pair(lines, cols);
}

Matrix::Matrix(std::pair<int,int> shape, float value)
{
    content = {};
    for (int i = 0 ; i<shape.first ; i++) {
        content.push_back (std::vector<float> (shape.second, value) ); 
    }
    this->shape = shape;
}

void Matrix::set(const int i, const int j ,const float value){
    content[i][j] = value;
}

void Matrix::Id()
{
    for (int i = 0 ; i<shape.first ; i++)
    {
        for (int j = 0 ; j < shape.second ; j++)
        {
            if (i == j) (set(i,i,1));
            else (set(i,j,0));
        }
    }
}

std::pair<int,int> Matrix::get_shape()
{
    return shape;
}

std::vector<float> Matrix::operator [] (int i)
{
    return content[i];
}

Matrix Matrix::operator + (const float a)
{
    Matrix res = Matrix(shape);
        for (int i = 0 ; i<shape.first ; i++){
            for (int j = 0 ; j < shape.second ; j++) {
                res.set(i, j, content[i][j] + a);
            }
        }
        return res;
}

Matrix Matrix::operator - (const float a)
{
    return *this + (-a);
}

/* Matrix Matrix::operator -(){
    return *this * (-1);
}
 */
Matrix Matrix::operator * (const float a)
{
    Matrix res = Matrix(shape);
        for (int i = 0 ; i<shape.first ; i++){
            for (int j = 0 ; j < shape.second ; j++) {
                res.set(i, j, content[i][j] * a);
            }
        }
        return res;
}

Matrix Matrix::operator + (Matrix &other)
{
    if (other.get_shape() != shape) {
        std::cout<<"Error : shapes must be the same \n";
        Matrix res = Matrix(shape);
        return res;
        }

    else {
        Matrix res = Matrix(shape);
        for (int i = 0 ; i<shape.first ; i++){
            for (int j = 0 ; j < shape.second ; j++) {
                res.set(i, j, content[i][j] + other[i][j]);
            }
        }
        return res;
    }
}

Matrix Matrix::operator - (Matrix &other)
{
    Matrix temp = other * (-1);
    return *this + other;
}

Matrix Matrix :: operator * (Matrix &other)
{
    std::pair<int,int> const other_shape = other.get_shape();
    if (other_shape.first != shape.second) {
        std::cout<<"Error : shapes must be the same \n";
        Matrix res = Matrix(shape);
        return res;
        }

    else {
        std::pair<int,int> const new_shape = std::make_pair(shape.first, other_shape.second);
        Matrix res = Matrix(new_shape);
        for (int i = 0 ; i<new_shape.first ; i++){
            for (int j = 0 ; j < new_shape.second ; j++) {
                float value = 0;
                for (int a = 0 ; a < shape.second ; a++){
                    value = value + content[i][a] * other[a][j];
                    
                }
                res.set(i,j,value);
            }
        }
        return res;
    }
}


void Matrix::print()
{
    for (int i = 0 ; i<shape.first ; i++) {
        std::cout<<"\n";
        for (int j = 0 ; j<shape.second ; j++){
            std::cout<<content[i][j]<<"\t";
        }
    }
    std::cout<<"\n";
}

Matrix Matrix::transpose()
{
    Matrix res = Matrix(shape.second, shape.first);
    for (int i = 0 ; i < shape.first ; i++)
    {
        for (int j = 0 ; j < shape.second ; j++)
        {
            res.set(j,i,content[i][j]);
        }
    }
    return res;

}

Matrix::~Matrix(){

}