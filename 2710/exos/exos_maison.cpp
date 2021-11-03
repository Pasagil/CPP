//pour convertir un char* en int : fonction atoi  (en C old school)
//int a = atoi(argv[4])
//plus actuel : on utilise std::string

//for (int i = 0 ; i < argc ; i++){
//  ...
//}
#include <iostream>

int main(int argc, char** argv){
    char* a = argv[1];
    int b = atoi(a);
    std::cout<< "premier argument : "<< a << std::endl;
    std::cout<<"converti en int avec atoi : "<< b << std::endl;
    std::cout<<"argv[1] + 1 = "<<b+1<<std::endl<<std::endl;
    
    std::cout<<" avec std::string :"<<std::endl;
    std::string c = std::string(a);
    int d = std::stoi(c);
    std::cout<<"argv[1] + 1 = "<<d+1<< std::endl<<std::endl;

    std::cout<<"fonction somme :"<<std::endl;
    int somme = 0;
    for (int i=0 ; i < argc - 1 ; i++){
        char* p = argv[i+1];
        std::string s = std::string(p);
        int k = std::stoi(s);
        somme = somme + k;
    }
    std::cout<<somme<<std::endl;
    return 0;
}