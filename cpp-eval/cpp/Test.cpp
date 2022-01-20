#include "Test.h"
#include <iostream>
int test(bool b)
{
    if (b)
    {
        std::vector<float> lin = std::vector<float> (2,3);
        std::vector<std::vector<float>> content = std::vector<std::vector<float>> (2,lin);
        Matrix mat0 = Matrix(content);
        mat0.print();
        Matrix mat1 = Matrix(2,2,1);
        Matrix mat2 = Matrix(2,2,1);
        mat1.print();
        mat2.print();
        Matrix mat3 = mat1 + mat2;
        mat3.print();
        Matrix mat4 = mat1 * mat2;
        mat4.print();
        Matrix line = Matrix(1,2,1);
        line.print();
        Matrix col = line.transpose();
        col.print();
        Matrix Identity = Matrix(2,2);
        Identity.print();
        Identity.Id();
        Identity.print();
        Matrix line0 = Identity.line(0);
        line0.print();
        Matrix col1 = Identity.col(1);
        col1.print();
        Identity.add_col(col);
        Identity.print();
        return 0;
    }
    return 0;
}