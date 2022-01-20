#include "Test.h"
#include <iostream>
int test(bool b)
{
    if (b)
    {
        //test des constructeurs
        std::vector<float> lin = std::vector<float> (2,3);
        std::vector<std::vector<float>> content = std::vector<std::vector<float>> (2,lin);
        Matrix mat0 = Matrix(content); 
        mat0.print();
        Matrix mat1 = Matrix(2,2,1);
        mat1.print();
        Matrix Identity = Matrix(2,2);
        Identity.Id();
        Identity.print();

        //test des opérateurs
        std::cout<<"\n \n \n";
        Matrix mat2 = Matrix(2,2,1);
        mat2.print();
        std::cout<<"\n + \n";
        mat1.print();
        std::cout<<"\n = \n";
        Matrix mat3 = mat1 + mat2;
        mat3.print();
        std::cout<<"\n \n \n";
        mat2.print();
        std::cout<<"\n * \n";
        mat1.print();
        std::cout<<"\n = \n";
        Matrix mat4 = mat1 * mat2;
        mat4.print();


        Matrix line0 = Identity.line(0);
        line0.print();
        Matrix col1 = Identity.col(1);
        col1.print();
        Identity.add_col(col1);
        Identity.print();
        return 0;
    }
    return 0;
}