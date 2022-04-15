#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

int gerar_random(){
    return (rand() % 10) + 1;
}

int gerar_random_menor(int n){
    return (rand() % n);
}

void show(vector<string> mapa){
    for(auto line : mapa){
        cout << line << endl;
    }
}

void queimar(vector<string>& floresta,  int nl, int nc){
    
    int nlmax = floresta.size();
    int ncmax = floresta[0].size();

    if (nl < 0 || nl >= nlmax || nc < 0 || nc >= ncmax)
        return;
    if (floresta[nl][nc] != '#') 
        return;
    
    floresta[nl][nc] = 'x';
    show(floresta);
    getchar();

    queimar(floresta, nl, nc - 1);
    queimar(floresta, nl - 1, nc );
    queimar(floresta, nl, nc + 1);
    queimar(floresta, nl + 1, nc);

}

int main(){

    srand(time(NULL));
    
    int nc = gerar_random();
    int nl = gerar_random();

    if(nc <= 1 || nl <= 1){
        nc++;
        nl++;
    }

    vector<string> floresta(nl, string(nc, '#'));


    for(int i = gerar_random_menor((nc * nl)); i > 0; i--){
        int randl = gerar_random_menor(nl);
        int randc = gerar_random_menor(nc);
        if(floresta[randl][randc] == '#'){
            floresta[randl][randc] = '.';
        }
    }

    show(floresta);

    int li{ }, ci{ };
    cin >> li >> ci;
    cin.ignore();

    queimar(floresta, li, ci);
}
    