#include "Matrix.h"
#include "Test.h"
#include "Resol.h"
#include <iostream>
// #include "matplotlibcpp.h"

// namespace plt = matplotlibcpp

int main()
{
    test(false);
    Resol res_const = Resol(0.05,0.01,true);
    Matrix T_expl_const = res_const.euler_explicit();
    T_expl_const.WriteToFile(std::string("T_expl_const.csv"));
    Matrix T_impl_const = res_const.euler_implicit();
    T_impl_const.WriteToFile(std::string("T_impl_const.csv"));
    // std::vector<int> x = T_expl_const.get_x();
    // for (int i = 0; i < T_expl_const.get_shape().second ; i++){
    //     plt::plot(x,T.col(i))
    // }


    Resol res = Resol(0.05,0.01,false);
    Matrix T_exp = res.euler_explicit();
    T_exp.WriteToFile(std::string("T_expl.csv"));
    Matrix T_imp = res.euler_implicit();
    T_imp.WriteToFile(std::string("T_impl.csv"));
}