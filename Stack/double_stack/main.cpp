#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> shelf;
    stack<int> deposit;

    int queries;
    cin >> queries;

    for(int i = 0; i < queries; i++){
        int cmd{};
        cin >> cmd;

        switch (cmd)
        {
        case 1:
            int value;
            cin >> value;
            deposit.push(value);
            break;
            
        case 2:
            shelf.pop();
            break;
        case 3:
            cout << shelf.top() << endl;
            break;
        case 4:
            cout << deposit.top() << endl;
            break;
        default:
            cout << "Comando invalido" << endl;
        }
        if(shelf.empty()){
            while(!deposit.empty()){
                shelf.push(deposit.top());
                deposit.pop();
            }
        }
    }
}