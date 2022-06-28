#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    queue<char> teams({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'});

    string who_win;

    while(teams.size() != 1){
        //cout << teams.back() << endl;

        who_win.push_back(teams.front());
        teams.pop();
        who_win.push_back(teams.front());
        teams.pop();

        string goals;
        input >> goals;

        if(goals[0] - '0' > goals[1] - '0'){
            cout << goals[0] - '0' << endl;
            teams.push(who_win[0]);
        }
        else{
            teams.push(who_win[1]);
        }
        who_win.clear();
    }
    cout << teams.back() << endl;
}