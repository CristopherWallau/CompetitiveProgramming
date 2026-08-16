#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1010;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y,int n,int m,vector<string>& grid){
// 1. CHECAGEM DE LIMITES (Segurança máxima)
    // Se saiu do mapa, aborta imediatamente!
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }
    
    // 2. CHECAGEM DE PAREDE
    // Se bateu numa parede (ou num chão que já transformamos em parede), aborta!
    if (grid[x][y] == '#') {
        return;
    }
    
    // 3. A MARCAÇÃO
    // É um chão válido! Transforma em parede para não voltarmos aqui
    grid[x][y] = '#';
    
    // 4. A INUNDAÇÃO (O poder da recursão)
    // Usamos o for e os vetores de direção para visitar os 4 vizinhos
    for (int i = 0; i < 4; i++) {
        int novo_x = x + dx[i];
        int novo_y = y + dy[i];
        
        dfs(novo_x, novo_y,n,m,grid); // Chama o robô para a próxima casa
    }
}
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int salas =0;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int x,y=0;
    // Cima, Baixo, Direita, Esquerda
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Se acharmos um pedaço de chão que ainda não foi visitado
            if (grid[i][j] == '.') {
                salas++;      // Achamos uma sala nova!
                dfs(i, j,n,m,grid);    // Manda a DFS pintar a sala inteira
            }
        }
    }

    cout << salas << "\n"; // Imprime a resposta
    return 0;
}