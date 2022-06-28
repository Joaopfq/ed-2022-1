#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int main(){
    ifstream input("input.txt");
    queue<char> teams({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'});

    while(teams.size() != 1){
        
        string who_win;

        who_win.push_back(teams.front());
        teams.pop();
        who_win.push_back(teams.front());
        teams.pop();

        int team_one, team_two;
        input >> team_one >> team_two;

        if(team_one > team_two){
            teams.push(who_win[0]);
        }
        else{
            teams.push(who_win[1]);
        }
    }
    cout << teams.back() << endl;
}