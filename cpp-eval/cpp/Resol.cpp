#include "Resol.h"
#include "math.h"
#include <random>

std::vector <float> Resol::get_x(){
    return x;
}

void Resol::set_dx(float const dx)
{
    this->dx = dx;
    Nx = xf / dx + 1;
    T.resize(Nx) ; D.resize(Nx) ; x.resize(Nx);
    for (int i=0 ; i < Nx ; i++)
    {
        x[i] = x0 + i*dx;
    }
}

void Resol::set_dt(float const ndt)
{
    this->dt = dx*dx/2;
    Nt = tf / dt + 1;
    t.resize(Nt) ;
    for (int i=0 ; i < Nt ; i++)
    {
        t[i] = t0 + i*dt;
    }
}

void Resol::set_D(bool const constant)
{
    if (constant) {
        std::fill(
            D.begin(), 
            D.end(), 
            1
        );
    }
    else {
    //the random device that will seed the generator
    std::random_device seeder;
    //then make a mersenne twister engine
    std::mt19937 engine(seeder());
    //then the easy part... the distribution
    std::uniform_int_distribution<int> dist(5, 15);
    //then just generate the integer like this:
    for (int i = 0 ; i < Nx ; i++){
        D[i] = float(dist(engine)) / float(10);
        std::cout<<D[i]<<std::endl;
        }
    }
}

void Resol::set_K()
{
    K = Matrix(Nx,Nx);
    for (int i = 0 ; i < Nx ; i++)
    {
        for (int j = 0 ; j < Nx ; j++)
        {
            if (j == i-1) (K.set(i,j,-D[i]));
            else if (j == i) (K.set(i,i,-(-D[i] - D[i+1])));
            else if (j == i+1) (K.set(i,j,-D[i+1]));
        }
    }
    K = K * (1/(dx*dx));
}

void Resol::set_init(){
    init.resize(Nx);
    for (int i = 0 ; i < Nx ; i++) {
        init[i] = 0.5 + sin(2*M_PI*x[i]) - 0.5 * cos(2*M_PI*x[i]);
    }
}

Resol::Resol(float const dx, float const dt, bool const constant){
    set_dx(dx) ; set_dt(dt) ; set_D (constant) ; set_K(); set_init();
}

Matrix Resol::gradient_conjugue(Matrix const &A, Matrix const &B){
    float const eps = 0.001;
    Matrix X = Matrix(B.get_shape());
    Matrix R = B;
    Matrix P = R;
    while (R.norm() > eps){
        float alpha = R.norm() / (sqrt((P.transpose() * A * P).norm()));
        X = X + (P * alpha);
        Matrix R1 = R - (A * P * alpha);
        float beta = R1.norm() / R.norm();
        P = R1 + P * beta;
        R = R1; 
    }
    return X;
}

Matrix Resol::euler_explicit()
{
    Matrix T = Matrix(std::vector<std::vector<float>> (1,x)).transpose();
    Matrix col_init = Matrix(std::vector<std::vector<float>> (1,init)).transpose();
    T.add_col(col_init);
     for (int i = 1 ; i < Nt ; i++){
        // Matrix T_col = T.col(i);
        // Matrix m1 = K * T_col;
        // Matrix m2 = m1 * dt;
        // Matrix col = T_col - m2;
        Matrix col = T.col(i) - (K * T.col(i) *dt);
        col.set(0,0,0);
        col.set(Nx-1,0,0);

        // Matrix m2 = m1 *
        // Matrix col = T_col - ((K * T_col) * dt);
        T.add_col(col);
    }

    return T;
}

Matrix Resol::euler_implicit(){
    Matrix T = Matrix(std::vector<std::vector<float>> (1,x)).transpose();
    Matrix col_init = Matrix(std::vector<std::vector<float>> (1,init)).transpose();
    T.add_col(col_init);
     for (int i = 1 ; i < Nt ; i++){
         Matrix A = Matrix(K.get_shape());
         A.Id();
         Matrix col = gradient_conjugue((K * dt) + A, T.col(i));
         col.set(0,0,0);
         col.set(Nx-1,0,0);
         T.add_col(col);
     }
     return T;
}