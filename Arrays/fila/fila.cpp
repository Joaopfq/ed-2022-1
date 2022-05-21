#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int size_f; 
    cin >> size_f;
    vector<int> fila;

    for(int i = 0; i < size_f; i++){
        int value;
        cin >> value;
        fila.push_back(value);
    }

    int size_s;
    cin >> size_s;
    vector<int> sairam;

    for(int i = 0; i < size_s; i++){
        int value;
        cin >> value;
        sairam.push_back(value);
    }

    for(int i = 0; i < size_s; i++){
        auto it = find(fila.begin(), fila.end(), sairam[i]);
        fila.erase(it);
    }

    cout << "[ ";

    for(int value : fila){
        cout << value << " ";
    }

    cout << "]";
}