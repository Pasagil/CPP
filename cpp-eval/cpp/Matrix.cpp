#include "Matrix.h"
#include "math.h"
#include <iostream>
#include <fstream>

Matrix::Matrix(std::vector<std::vector<float>> const lines)     
{
    content = lines;
    shape = std::make_pair(content.size(), content[0].size());
}

Matrix::Matrix(int const  lines, int const cols, float const value)
{
    content = {};
    for (int i = 0 ; i<lines ; i++) {
        content.push_back (std::vector<float> (cols, value) );   
    }
    shape = std::make_pair(lines, cols);
}

Matrix::Matrix(std::pair<int,int> const shape, float const value)
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

std::pair<int,int> Matrix::get_shape() const
{
    return shape;
}

std::vector<float> Matrix::operator [] (const int i) const
{
    return content[i];
}

Matrix Matrix::operator + (const float a) const
{
    Matrix res = Matrix(shape);
        for (int i = 0 ; i<shape.first ; i++){
            for (int j = 0 ; j < shape.second ; j++) {
                res.set(i, j, content[i][j] + a);
            }
        }
        return res;
}

Matrix Matrix::operator - (const float a) const
{
    return *this + (-a);                           
}

Matrix Matrix::operator * (const float a) const
{
    Matrix res = Matrix(shape);
        for (int i = 0 ; i<shape.first ; i++){
            for (int j = 0 ; j < shape.second ; j++) {
                res.set(i, j, content[i][j] * a);
            }
        }
        return res;
}

Matrix Matrix::operator + (Matrix const &other) const
{
    if (other.get_shape() != shape) {                       //si les tailles ne correspondent pas, on renvoie une matrice nulle
        std::cout<<"Error : shapes must be the same \n";    //de la taille de la matrice de gauche
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

Matrix Matrix::operator - (Matrix const &other) const
{
    Matrix temp = other * (-1);
    return *this + temp;
}

Matrix Matrix :: operator * (Matrix const &other) const
{
    std::pair<int,int> const other_shape = other.get_shape();
    if (other_shape.first != shape.second) {
        std::cout<<"Error : shapes must be (n,m),(m,l) \n";
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


void Matrix::print() const
{
    for (int i = 0 ; i<shape.first ; i++) {
        std::cout<<"\n";
        for (int j = 0 ; j<shape.second ; j++){
            std::cout<<content[i][j]<<"\t";
        }
    }
    std::cout<<"\n";
}

Matrix Matrix::transpose() const
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

Matrix Matrix::line(int i) const{
    return Matrix(std::vector<std::vector<float>> (1, content[i]));
}

Matrix Matrix::col(int j) const {
    return transpose().line(j).transpose();
}

float Matrix::norm() const {
    float s = 0;
    for (int i = 0 ; i<shape.first ; i++){
        s = s + pow(content[i][0], 2);
    }
    return s;
}

void Matrix::add_col(Matrix const &col) {
    for (int i = 0 ; i<col.shape.first ; i++){
        content[i].push_back(col.content[i][0]);
    }
    shape = std::make_pair(shape.first, shape.second +1);   
    }

void Matrix::WriteToFile(const std::string &file_name) const
{
    std::ofstream out(std::string("./data/") + file_name);

    unsigned int k = 0;
    for (unsigned int i = 0; i < shape.first; i++)
    {
        for (unsigned int j = 0; j < shape.second; j++)
        {
            out << content[i][j] << ",";
        }
        out << "\n";
    }
}
    
Matrix::~Matrix(){
}