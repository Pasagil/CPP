#include "resol.h"

void Resol::set_dx(float const dx)
{
    Nx = xf / dx
    T.resize(Nx) ; D.resize(Nx) ; x.resize(Nx);
}

void Resol::set_dt(float const dt)
{
    this->dt = dt;
    Nt = tf / dt
    t.resize(Nt) ;
    for (i=0 ; i < Nt ; i++)
    {
        t[i] = t0 + i*dt;
    }
}

void Resol::set_D(bool const constant)
{
    if (constant = true) {
        std::fill(
            D.begin(), 
            D.end(), 
            1
        )
    }
    else ()
}

void Resol::set_K()
{
    K = Matrix(Nx,Nx)
    for (int i = 0 ; i < Nx ; i++)
    {
        for (int i = 0 ; i < Nx ; i++)
        {
            if (j == i-1) (K.set(i,j,D[i]));
            else if (j == i) (K.set(i,i,-D[i] - D[i+1]));
            else if (j == i+1) (K.set(i,j,D[i+1]));
        }
    }
}

std::vector<std::vector<float>> Resol::resol(float const dx, float const dt, bool const constant)
{
    set_dx(dx) ; set_dt(dt) ; set_D (constant) ; set_K();
    Matrix T = Matrix(Nx, Nt)
}
