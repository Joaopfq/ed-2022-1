#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show(vector<string> mat){
    for(auto line : mat){
        cout << line << endl;
    }
}

bool pode_furar(vector<string> mat, vector<pair<int, int>> vizinhos, int nl, int nc){

    int qtd {0};
    int nlmax = mat.size();
    int ncmax = mat[0].size();

    if(mat[nl][nc] == ' ')
        return false;

    for(auto vizinho : vizinhos){
        if(vizinho.first < 0 || vizinho.first >= nlmax || vizinho.second < 0 || vizinho.second >= ncmax)
            continue;

        if(mat[vizinho.first][vizinho.second] == '#')
            qtd++;

    }
    if(qtd >= 3)
        return true;

    return false;
}

void derrubar_parede(vector<string>& mat, int nl, int nc){

    int nlmax = mat.size();
    int ncmax = mat[0].size();

    if(nl < 0 || nl >= nlmax || nc < 0 || nc >= ncmax)
        return;

    vector<pair<int, int>> vizinhos;
    vizinhos.push_back({nl, nc - 1});
    vizinhos.push_back({nl, nc + 1});
    vizinhos.push_back({nl - 1, nc});
    vizinhos.push_back({nl + 1, nc});

    if(pode_furar(mat, vizinhos, nl, nc)){
        mat[nl][nc] = ' ';
        show(mat);
        cout << '\n';

        random_shuffle(vizinhos.begin(), vizinhos.end());

        for(auto vizinho : vizinhos){
            derrubar_parede(mat, vizinho.first, vizinho.second);
        
        }
    }
}

int main(){
    int nl{0}, nc{0};
    cin >> nl >> nc;

    vector<string> mat;

    for(int i = 0; i < nl; i++){
        string line(nc, '#');
        mat.push_back(line);
    }

    derrubar_parede(mat, 4, 5);
}