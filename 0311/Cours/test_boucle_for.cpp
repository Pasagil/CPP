#include <iostream>

int main(){

    //marche : quand on crée un tableau, le compil "connaît" la taille 
    const char value[] {"Hello World"};
    for( char c: value){
        std::cout << c << std::endl;
    }

    //marche, ce qu'il faut faire
    const std::string value {"Hello World"};
    for( char c: value){
        std::cout << c << std::endl;
    }

    //marche pas
    const char* value {"Hello World"};
    for( char c: value){
        std::cout << c << std::endl;
    }
}

