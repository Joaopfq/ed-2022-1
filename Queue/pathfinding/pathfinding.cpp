#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct Pos{
    int l;
    int c;

    Pos(int l, int c){
        this->c = c;
        this->l = l;
    }
};

vector<Pos> find_nbhd(Pos atual){
    auto [l,c] = atual;

    return {{l - 1, c}, {l + 1, c}, {l, c - 1}, {l, c + 1}};
}

void show(vector<string> mat){
    for(string line : mat) {
        cout << line << endl;
    }
}

void find_way_back(vector<vector<int>> &dis, vector<string> &mat, Pos fim){
    Pos atual = fim;
    bool find{false};

    while(!find){
        for(auto nb : find_nbhd(atual)){
            if(nb.l == (int)mat.size() || nb.l < 0 || nb.c == (int)mat[0].size() || nb.c < 0) {
                continue;
            }

            if(dis[nb.l][nb.c] == dis[atual.l][atual.c] - 1){
                mat[atual.l][atual.c] = '.';
                atual = nb;
            }

            if(mat[atual.l][atual.c] == 'I'){
                mat[atual.l][atual.c] = '.';

                find = true;
            }
        }
    }
}

void find_exit(vector<string> &mat, Pos inicio, Pos fim){
    vector<vector<int>> dis(mat.size(), vector<int>(mat[0].size(), -1));
    queue<Pos> queue;
    queue.push(inicio);
    dis[inicio.l][inicio.c] = 0;

    while(queue.size() != 0){
        Pos atual = queue.front();

        for(auto nb : find_nbhd(atual)){
            if(nb.l == (int)mat.size() || nb.l < 0 || nb.c == (int)mat[0].size() || nb.c < 0) {
                continue;
            }

            if(mat[nb.l][nb.c] == 'F' || (mat[nb.l][nb.c] == ' ' && dis[nb.l][nb.c] == -1)){
                queue.push(nb);
                dis[nb.l][nb.c] = dis[atual.l][atual.c] + 1;
            }

            if(mat[nb.l][nb.c] == 'F'){
                find_way_back(dis, mat, fim);
                return;
            }
        }
        queue.pop();
    }
}


int main(){
    int nl{},nc{};

    cin >> nl >> nc;

    cin.ignore();

    vector<string> mat(nl);

    for(int i = 0; i < nl; i++){
        getline(cin, mat[i]);
    }

    Pos inicio(0,0), fim(0,0);

    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                fim = Pos {l, c};
            }
        }
    }

    find_exit(mat, inicio, fim);    
    show(mat);
}