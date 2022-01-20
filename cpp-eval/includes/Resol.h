#include "Matrix.h"
#include <iostream>
#include <vector>

class Resol {

    private:
    std::vector <float> t;                  //contient tous les tj
    std::vector <float> x;                  //contient tous les xj
    std::vector <std::vector<float>> T;     // 1 vecteur = l'évolution en temps à x fixé
    std::vector <float> D;
    Matrix K = Matrix(0,0);
    float t0 = 0, tf = 0.5;
    float x0 = 0, xf = 1;
    float dt;
    float dx;
    int Nt, Nx;                             //nombres de points en temps et en position
    std::vector<float> init;                //conditions initiales

    public:
    Resol(float const dx, float const dt, bool const constant); //construit un solveur, avec d constant si constant=true, aléatoire sinon
    std::vector <float> get_x();   

    //attribution des paramètres                      
    void set_dx(float const dx);
    void set_dt(float const dt);
    void set_D(bool const constant);
    void set_K();
    void set_init();

    Matrix gradient_conjugue(Matrix const &A, Matrix const &B); //renvoie la colonne X solution de AX = B
    Matrix euler_explicit();                                    //renvoie le tableau des températures calculé avec euler explicite
    Matrix euler_implicit();                                        
};