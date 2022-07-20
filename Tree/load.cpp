#include <iostream>

using namespace std;

int main(){
    string entrada;

    cin >> entrada;
    string resposta = "[ ";


    for(char c : entrada){
        if(c == '#')
            continue;
        else{
            resposta = resposta + c + " ";
        }
    }
    resposta = resposta + ']';


    cout << resposta << endl;
}