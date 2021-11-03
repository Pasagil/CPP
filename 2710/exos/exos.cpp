//include des librairies
#include <iostream>
int main(){
    //ex 2
    std::cout<<"Devoirs de c++" <<std::endl ;
    int i = 10;
    int j = 3;
    double x = 3;
    std::cout<<i/j<<std::endl; //entier/entier = entier
    std::cout<<i/x<<std::endl; //entier/float = float -> on garde la plus grande précision ?

    int i2 = 32768;
    short int j2 = i2;         // cast de la variable
    std::cout<<j2<<std::endl; //dépassement
    std::cout<<sizeof(int) << sizeof(long) << sizeof(short int) << sizeof(float) << sizeof(double) <<std::endl;
}