#include <iostream>
#include <list>
#include <vector>
#include "Cliente.hpp"


using namespace std;

class Bank{

    vector<Client*> caixas;
    list<Client*> queue_in;
    list<Client*> queue_out;
    int received {0};       
    int lost {0};           
    int tics {0};

public:
    Bank(int n_caixas){
        vector<Client*> caixas (n_caixas, nullptr);
        this->caixas =  caixas;
    } 

    int getReceived(){
        return this->received;
    }

    int getLost(){
        return this->lost;
    }

    int getTics(){
        return this->tics;
    }

    void insert(Client * client){
        queue_in.push_back(client);
    }

    
    bool empty(){
        int aux{0};
        for(auto client : caixas){
            if(client != nullptr)
                aux++;
        }

        if(queue_in.empty() && queue_out.empty() && aux == 0)
            return true;
        return false;
    }

    void tic(){
        while(!queue_out.empty()){
            delete queue_out.front();
            queue_out.pop_front();
        }

        for(int i = 0; i < (int)caixas.size(); i++){
            if(caixas[i] != nullptr){
                if(caixas[i]->getDocs() != 0){
                    caixas[i]->decrease_docs();
                    this->received++;
                }
                else{
                    queue_out.push_back(caixas[i]);
                    caixas[i] = nullptr;
                }
            }

            else{               
                    if(!queue_in.empty()){
                        this->caixas[i] = queue_in.front();
                        queue_in.pop_front();
                    }
            }
        }
        
        for(auto it = queue_in.begin(); it != queue_in.end();){

            if((*it)->getPac() != 0){
                (*it)->decrease_pac();
                it++;
            }
            else{
                queue_out.push_back(*it);
                this->lost += (*it)->getDocs();
                it = queue_in.erase(it);          
            }

        }
        this->tics++;
    }



    void show_all(){
        for(auto client : caixas){
            cout << "[" << (client == nullptr ? "" : client->str()) << "]";
        }
        cout << "\nin :{ ";
        for(auto client : queue_in)
            cout << client->str() << " ";
        cout << "}\nout:{ ";
        for(auto client : queue_out)
            cout << client->str() << " ";
        cout << "}\n";
    }
};