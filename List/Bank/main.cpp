#include <iostream>
#include <sstream>
#include "Bank.hpp"

using namespace std;

int main(){
    Bank banco(3);

    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        if(cmd == "show"){
            banco.show_all();
        }else if(cmd == "in"){
            string name;
            int docs, patience;
            ss >> name >> docs >> patience;
            banco.insert(new Client(name, docs, patience));
        }else if(cmd == "init"){
            int size;
            ss >> size;
            banco = Bank(size);
        }else if(cmd == "tic"){
            banco.tic();
        }else if(cmd == "finish"){
            while(!banco.empty())
                banco.tic();
            cout << "received: " << banco.getReceived() << endl;
            cout << "lost: " << banco.getLost() << endl;
            cout << "tics: " << banco.getTics() << endl;
        }else{
            cout << "fail: command not found\n";
        }
    }
}