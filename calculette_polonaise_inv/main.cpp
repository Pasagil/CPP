#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char** argv){

    vector<string> vec = {};

    for (int i=1 ; i<argc ; i++ ) 

    {
        string c = argv[i];

        if (c == "+")
        {
            string a = vec.back();
            vec.pop_back();     
            string b = vec.back();
            vec.pop_back();
            vec.push_back(to_string(stof(a) + stof(b)));
        }

        else if (c == "-")
        {
            string a = vec.back();
            vec.pop_back();     
            string b = vec.back();
            vec.pop_back();
            vec.push_back(to_string(stof(a) - stof(b)));
        }

        else if (c == "x")
        {
            string a = vec.back();    
            vec.pop_back();
            string b = vec.back();
            vec.pop_back();
            vec.push_back(to_string(stof(a) * stof(b)));
        }

        else if (c == "/")
        {
            string a = vec.back();   
            vec.pop_back();  
            string b = vec.back();
            vec.pop_back();
            vec.push_back(to_string(stof(a) / stof(b)));
        }

        else 
        {
            vec.push_back(c);
        }
    }
    cout<<vec[0]<<endl;
    return 0;

}
