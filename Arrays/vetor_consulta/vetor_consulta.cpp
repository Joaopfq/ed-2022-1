#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

vector<int> matching_strings(vector<string> consulta, vector<string> busca) {
    vector<int> v_contador{};
    int contador{};

    for(int i = 0; i < (int)busca.size();  i++) {
        for(int j = 0; j < (int)consulta.size(); j++) {
            if(consulta[j] == busca[i]) {
                contador++;
            }
        }
        v_contador.push_back(contador);
        contador = 0;
    }
    return v_contador;
}

int main(){
    vector<string> consulta;
    int size_c{ };
    vector<string> busca;
    int size_b{ };
    ifstream input("input.txt");

    input >> size_c;

    for(int i = 0; i < size_c; i++) {
        string line;
        input >> line;
        consulta.push_back(line);
    }

    input >> size_b;

    for(int i = 0; i < size_b; i++) {
        string line;
        input >> line;
        busca.push_back(line);
    }
    
    vector<int> qtd_ocorrencias = matching_strings(consulta, busca);
    
    for(int value : qtd_ocorrencias){
        cout << value << " ";
    }
    
}