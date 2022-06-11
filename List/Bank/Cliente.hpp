#include <iostream>

using namespace std;

class Client{
    string name;
    int docs;
    int pac;

public:

    Client(string name, int actions, int pac){
        this->name = name;
        this->docs = actions;
        this->pac = pac;
    }

    void decrease_docs(){
        this->docs--;
    }

    void decrease_pac(){
        this->pac--;
    }

    int getPac(){
        return this->pac;
    }

    int getDocs(){
        return this->docs;
    }

    string str(){
        return name + ":" + to_string(docs) + ":" + to_string(pac);
    }
};