#include "Matrix.h"
#include <iostream>
#include <vector>

class Resol {

    private:
    std::vector <float> t;
    std::vector <float> x;
    std::vector <std::vector<float>> T;     // 1 vecteur = l'évolution en temps à x fixé
    std::vector <float> D;
    Matrix K = Matrix(0,0);
    float t0 = 0, tf = 0.5;
    float x0 = 0, xf = 1;
    float dt;
    float dx;
    int Nt, Nx;
    std::vector<float> init;

    public:
    Resol(float const dx, float const dt, bool const constant);
    std::vector <float> get_x();
    void set_dx(float const dx);
    void set_dt(float const dt);
    void set_D(bool const constant);
    void set_K();
    void set_init();
    Matrix gradient_conjugue(Matrix const &A, Matrix const &B);
    Matrix euler_explicit();
    Matrix euler_implicit();
};