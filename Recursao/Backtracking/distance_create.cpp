#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


bool can_put(string& line, int index, int value, int prox){
    vector<int> posicoes;
    
    for(int i = index + 1; i < index + 1 + prox; i++){
        posicoes.push_back(i);
        if(i < (int)line.size() && line[i] == value + '0')  
            return false;
    }
    for(int i = index - prox; i < index; i++)
        if(i >= 0 && line[i] == value + '0')
            return false;
    
    return true;
}

bool fill(string& line, int i, int lim, int prox){
    if((int)line.size() == i){
        cout << line << "<---\n";
        return true;
    }
        
    if(line[i] != '.')
        return fill(line, i + 1, lim, prox);


    for(int value = 0; value <= lim; value++) {
        if(can_put(line, i, value, prox)){
            line[i] = value + '0';
            cout << line << endl;
            if(fill(line, i + 1, lim, prox))
                return true;
        }
    }

    line[i] = '.';
    cout << line << endl;
    return false;
}

int main(){
    ifstream input("input.txt");
    string line;
    int prox;
    int lim = 4;

    input >> line >> prox;

    fill(line, 0, lim, prox);
}