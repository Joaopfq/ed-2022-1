#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int found_alive(vector<bool>& fila, int pos){
    do{
        pos = (pos + 1) % fila.size();
    } while(fila[pos] == false);

    return pos;
}


void show(vector<bool>& fila, int size, int sword){
    string str;
    for(int i = 0; i <= size; i++) {
        if(fila[i]) {
            if(i == sword) {
                str = str + to_string(i) + "> ";
                
            } else {
                str = str + to_string(i) + " ";
            }
        }
    }
    cout << str << endl;
}

int main(){
    int size = 0, sword = 0;

    cin >> size;
    cin >> sword;
    vector<bool> fila;

    for(int i = 0; i < size; i++) {
        fila.push_back(true);
    }
    int qtd = size + 1;

    while(qtd--){
        show(fila, size, sword);
        fila[found_alive(fila,sword)] = false;
        sword = found_alive(fila, sword);
    }
}