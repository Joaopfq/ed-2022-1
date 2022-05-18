#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    int size;
    input >> size;
    vector<int> vet;

    int rot;
    input >> rot;
    
    for(int i = 0; i < size; i++){
        int value; 
        input >> value;
        vet.push_back(value);
    }
    // 3 2 1
    // 3

    for(int i = 0; i < rot; i++){
        int aux = vet[size - 1];
        vet.pop_back();
        vet.push_back(vet[0]);
        vet[0] = aux; 
    }

    cout << "[ ";

    for(int value : vet){
        cout << value << " ";
    }

    cout << "]";
}