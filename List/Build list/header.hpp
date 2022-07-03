#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

struct List{
    Node * head {nullptr};

    List(){
    }

    bool empty(){
        return this->head == nullptr;
    }

    void push_back(int value){

        if(head == nullptr){
            head = new Node(value);
            return;
        }

        auto node = head;

        while(node->next != nullptr)
            node = node->next;
        
        node->next = new Node(value);
    }

    void push_front(int value){
        auto node = new Node(value);

        if(this->head == nullptr){
            this->head = node;
            return;
        }
        node->next = head;

        this->head = node;
    }

    void pop_back(){
        if(this->head == nullptr)
            return;
        
        if(head->next == nullptr){
            pop_front();
            return;
        }

        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        
        delete node->next;
        node->next = nullptr;  
    }

    void pop_front(){
        if(this->head == nullptr)
            return;

        auto node = head;
        head = head->next;
        delete node;
    }

    int size(){
        int size{1};

        if(this->head == nullptr)
            return 0;

        auto node = head;

        while(node->next != nullptr){
            node = node->next;
            size++;
        }
        return size;
    }

};