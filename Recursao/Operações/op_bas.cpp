#include <iostream>
#include <list>
#include <sstream>

using namespace std;


void mostrar_lista(list<int> lista) {

    cout << lista.front() << " ";
    lista.erase(lista.begin());
    if((int)lista.size() == 0) {
        return;
    }
    mostrar_lista(lista);
}

void mostrar_rlista(list<int> lista) {
    cout << lista.back() << " ";
    lista.pop_back();
    if((int)lista.size() == 0) {
        return;
    }
    mostrar_rlista(lista);
}

void somar(list<int> lista, int soma) {


    soma = soma + lista.front();
    lista.erase(lista.begin());

    if((int)lista.size() == 0) {
        cout << soma << endl;
    }

    somar(lista, soma);
}

void mult(list<int> lista, int mul) {

    if(mul == 0) {
        mul++;
    }

    mul = mul * lista.front();
    lista.erase(lista.begin());

    if((int)lista.size() == 0) {
        cout << mul << endl;
    }

    mult(lista, mul);
}

void menor(list<int> lista, int men) {
    
    if(lista.front() < men){
        men = lista.front();
    }

    lista.erase(lista.begin());

    if((int)lista.size() == 0) {
        cout << men << " ";
    }
    
    menor(lista, men);
}

void invert(list<int> lista){
    lista.reverse();
    mostrar_lista(lista);
}

int main() {
 
    list<int> lista{55, 21, 33, 30};


    invert(lista);

}
