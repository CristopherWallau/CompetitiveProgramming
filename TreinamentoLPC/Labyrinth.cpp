#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<string> rastros;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char direcao[] = {'U', 'D', 'R', 'L'};
typedef pair<int, int> ii;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs(int start_x, int start_y) {
    queue<ii> fila; 
    
    // Inicia a fila com o ponto 'A'
    fila.push({start_x, start_y});
    rastros[start_x][start_y] = 'A'; // O ponto de origem

    // Loop da BFS (Processando a fila)
    while(!fila.empty()) {
        auto [x, y] = fila.front();
        fila.pop();

        // Se chegou no destino, encerra a busca antecipadamente!
        if (grid[x][y] == 'B') {
            break; 
        }

        // Expansão para os 4 lados
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Checagem de segurança (dentro do mapa, não é parede, não foi visitado)
            if (isValid(nx, ny) && grid[nx][ny] != '#' && rastros[nx][ny] == 'X') {
                rastros[nx][ny] = direcao[i]; // Salva de onde viemos
                fila.push({nx, ny});          // Coloca na fila
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    grid.resize(n);
    rastros.assign(n, string(m, 'X'));
    
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // No Labyrinth, procuramos as coordenadas do ponto 'A' para iniciar
    int start_x = -1, start_y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    // Dispara a BFS
    if (start_x != -1) {
        bfs(start_x, start_y);
    }
    int start_b = -1, start_yb = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                start_b = i;
                start_yb = j;
            }
        }
    }
    if(rastros[start_b][start_yb] == 'X'){
        cout << "NO" << "\n";
        return 0;
    }
    else{
        string caminho = "";
        char letra;
        cout << "YES" << "\n";
        while(rastros[start_b][start_yb] != 'A'){
            letra = rastros[start_b][start_yb];
            caminho += letra;
            if(letra == 'U'){
                start_b++;
            }
            else if(letra == 'D'){
                start_b--;
            }
            else if(letra == 'R'){
                start_yb--;
            }
            else
                start_yb++;
        }
    reverse(caminho.begin(), caminho.end());
    cout << caminho.size() <<"\n";
    cout << caminho << "\n";
    }
    return 0;
}