#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");

    vector<int> vet;
    int size;
    input >> size;

    int rot;
    input >> rot;

    if(rot > size)
        rot = rot % size;

    for(int i = 0; i < size; i++) {
        int value; 
        input >> value;
        vet.push_back(value);
    }

    vector<int> aux;

    for(int i = size - 1; rot > 0; i--) {
        aux.push_back(vet[i]);
        vet.pop_back();
        rot--;
    }

    for(int i = 0; i < (int)aux.size(); i++) {
        auto it = vet.begin();
        vet.insert(it, aux[i]);
    }

    cout << "[ ";

    for(int value : vet){
        cout << value << " ";
    }

    cout << "]";
}