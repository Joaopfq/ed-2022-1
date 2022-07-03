#include "header.hpp"

ostream& operator<<(ostream& os, List& lista) {
    os << "[ ";
    Node * node = lista.head;
    while(node != nullptr) {
        os << node->value << " ";
        node = node->next;
    }
    os << "]";
    return os;
}

int main(){
    List lista;

    lista.push_front(7);
    lista.push_back(9);
    cout << lista;

}