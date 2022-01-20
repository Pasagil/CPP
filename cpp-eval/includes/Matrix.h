#pragma once
#include <vector>
#include <string>

class Matrix
{
    std::vector<std::vector<float>> content {};         //le contenu est un vecteur contenant les lignes.
    std::pair<int,int> shape;                           //la taille (lignes, colonnes) 

    public:
    //constructors
    Matrix(std::vector<std::vector<float>> const lines);                //depuis un vecteur de vecteurs, qui deviendra content
    Matrix(std::pair<int,int> const shape, float const value = 0);      //en donnant une std::pair d'entiers, qui deviendra shape
    Matrix(int const lines, int const cols, float const value = 0);     //en donnant le nombres de lignes puis de colonnes
                                                                        //"value" est la valeur de tous les éléments de la matrice
    void Id();                                                          //transforme une matrice en l'identité
    ~Matrix();
    //operators
    std::vector<float> operator [] (int const i) const;                 //renvoie la ligne i
    Matrix operator + (const float a) const;                            
    Matrix operator - (const float a) const;
    Matrix operator * (const float a) const;
    Matrix operator + (Matrix const &obj) const;
    Matrix operator * (Matrix const &obj) const;
    Matrix operator - (Matrix const &obj) const;

    // others
    void set(const int i, const int j, const float value);              //remplace la valeur dans la matrice à la place (i,j)
    std::pair<int,int> get_shape() const;                               
    Matrix transpose() const;
    Matrix line(int i) const;                                           //renvoie la i-ème ligne
    Matrix col(int j) const;                                            //renvoie la i-ème colonne
    float norm() const;                                                 //uniquement pour une ligne : renvoie la norme au carré
    void add_col(Matrix const &col);                                    //ajoute une colonne à la matrice
    void print() const;                                                 //affiche la matrice
    void WriteToFile(const std::string& file_name) const;               //construit un fichier csv contenant la matrice.
};