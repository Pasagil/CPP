#include <vector>

class Matrix
{
    std::vector<std::vector<float>> content {};
    std::pair<int,int> shape;

    public:
    //constructors
    Matrix(std::vector<std::vector<float>> cols);
    Matrix(std::pair<int,int> shape, float value = 0);
    Matrix(int lines, int cols, float value = 0);
    void Id ();
    ~Matrix();
    //operators
    std::vector<float> operator [] (int i);
    Matrix operator + (const float a);
    Matrix operator - (const float a);
    // Matrix operator - ();
    Matrix operator * (const float a);
    Matrix operator + (Matrix &obj);
    Matrix operator * (Matrix &obj);
    Matrix operator - (Matrix &obj);

    // others
    void set(const int i, const int j, const float value);
    std::pair<int,int> get_shape();
    Matrix transpose();
    void print();
 

};