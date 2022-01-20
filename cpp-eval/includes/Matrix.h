#pragma once
#include <vector>
#include <string>

class Matrix
{
    std::vector<std::vector<float>> content {};
    std::pair<int,int> shape;

    public:
    //constructors
    Matrix(std::vector<std::vector<float>> const lines);
    Matrix(std::pair<int,int> const shape, float const value = 0);
    Matrix(int const lines, int const cols, float const value = 0);
    void Id();
    ~Matrix();
    //operators
    std::vector<float> operator [] (int const i) const;
    Matrix operator + (const float a) const;
    Matrix operator - (const float a) const;
    Matrix operator * (const float a) const;
    Matrix operator + (Matrix const &obj) const;
    Matrix operator * (Matrix const &obj) const;
    Matrix operator - (Matrix const &obj) const;

    // others
    void set(const int i, const int j, const float value);
    std::pair<int,int> get_shape() const;
    Matrix transpose() const;
    Matrix line(int i) const;
    Matrix col(int j) const;
    float norm() const;
    void add_col(Matrix const &col);
    void print() const;
    void WriteToFile(const std::string& file_name) const;
};