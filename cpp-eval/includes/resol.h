#include "Matrix.h"
#include <iostream>
#include <vector>

class Resol {
    std::vector <float> t;
    std::vector <float> x;
    std::vector <std::vector<float>> T;     // 1 vecteur = l'évolution en temps à x fixé
    std::vector <float> D;
    Matrix K;
    float t0 = 0, tf = 0.5;
    float x0 = 0, xf = 1;
    float dt;
    int Nt, Nx;
    
    public:
    void set_dx(float const dx);
    void set_dt(float const dt);
    void set_D(bool const constant);
    void set_K();
    Matrix resol(float const dx, float const dt, bool const constant);
    
};