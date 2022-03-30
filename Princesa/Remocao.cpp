#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void show(vector<int>& fila, int sword) {
    string str;
    for(int pessoa : fila){
        if(pessoa == sword){
            str = str + to_string(pessoa) + "> ";
        } else {
            str = str + to_string(pessoa) + " ";
        }
    }
    cout << str << endl;
}

vector<int>::iterator get_it(vector<int>::iterator it, vector<int>& fila){
    if(it == fila.end()){
        return fila.begin();
    }   
    return it;
}

int main(){
    int sword{};
    int size{};

    cin >> size;
    cin >> sword;

    vector<int> fila(size);

    auto it_sword = fila.begin() + sword;

    iota(fila.begin(), fila.end(), 0);

    while(true) {
        show(fila, *it_sword);
        if((int)fila.size() > 0){

            auto it_victim = get_it(++it_sword, fila);
            it_sword = get_it(fila.erase(it_victim), fila);

        } else{
            break;
        }
    }
    
}