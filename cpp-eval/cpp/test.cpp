#include "test.h"
int test(bool b)
{
    if (b)
    {
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
        return 0;
    }
    else (return 0);
}