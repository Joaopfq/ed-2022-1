#include <iostream>
#include <list>
#include <numeric>

using namespace std;

void show(list<int>& fila, int sword) {
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

list<int>::iterator get_it(list<int>::iterator it, list<int>& fila){
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

    list<int> fila(size);

    auto it_sword = fila.begin();

    iota(fila.begin(), fila.end(), 0);

    while((int)fila.size() != 0) {
        show(fila, *it_sword);
        auto it_victim = get_it(++it_sword, fila);
        it_sword = get_it(fila.erase(it_victim), fila);
    }
    
}