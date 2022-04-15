#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void show(vector<string> labirinto){
    for(auto line : labirinto){
        cout << line << endl;
    }
}

void andar(vector<string>& labirinto, int nl, int nc){
    int nlmax = labirinto.size();
    int ncmax = labirinto[0].size();
    
    if(nl < 0 || nl >= nlmax || nc < 0 || nc >= ncmax)
        return;
    if(labirinto[nl][nc] != '_')
        return;

    labirinto[nl][nc] = '.';
    show(labirinto);
    getchar();

    andar(labirinto, nl, nc - 1);
    andar(labirinto, nl - 1, nc);
    andar(labirinto, nl, nc + 1);
    andar(labirinto, nl + 1, nc);
}

int main(){
    ifstream entrada("entrada.txt");


    int nl{ }, nc{ }, li{ }, ci{ };

    entrada >> nl >> nc;
    vector<string> labirinto;
    
    for(int i = 0; i < nl; i++){
        string line;
        entrada >> line;
        labirinto.push_back(line);
    }
    show(labirinto);
    cin >> li >> ci;
    cin.ignore();

    andar(labirinto, li, ci);

}