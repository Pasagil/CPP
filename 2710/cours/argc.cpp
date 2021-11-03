#include <iostream>

int main(int argc,char**argv){
    std::cout<<"nombre de paramètre : " << argc<<std::endl;
    std::cout<<"adresse du pointeur : " << argv <<std::endl;
    std::cout<<"pointeur 0 :" << (long)argv[0] <<std::endl;
    std::cout<<"pointeur 1 :" << (long)argv[1] <<std::endl;
    std::cout<<"pointeur 2 :" << (long)argv[2] <<std::endl;
    std::cout<<sizeof(int*)<<std::endl; 
    return (0);
}
char param[10];
char *pparam = param;

//pour convertir un char* en int : fonction atoi  (en C old school)
//int a = atoi(argv[4])
//plus actuel : on utilise std::string

//for (int i = 0 ; i < argc ; i++){
//  ...
//}