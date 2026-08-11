#include <bits/stdc++.h>
using namespace std;

int main() {
    // O combo para leitura rápida (evita Time Limit Exceeded)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Lendo os pontos. Usamos long long porque a distância pode ficar muito grande
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // D guarda as distâncias entre estrelas adjacentes
    vector<long long> D(n - 1);
    for (int i = 0; i < n - 1; i++) {
        D[i] = abs(x[i] - x[i+1]) + abs(y[i] - y[i+1]);
    }

    // C guarda a parte "constante" das nossas equações para cada R_i
    // Usando tamanho n + 1 para a matemática ficar indexada em 1
    vector<long long> C(n + 1, 0);
    C[1] = 0; 
    for(int i = 2; i <= n; i++){
        C[i] = D[i - 2] - C[i - 1]; // D[i-2] é a distância entre as estrelas (i-1) e i
    }

    long long L = 1; // Nosso k mínimo é 1, pois R_1 >= 1
    long long U = 2e18; // Limite superior inicialmente "infinito"

    // Analisa as restrições para cada estrela
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) { // i é ímpar: R_i = k + C[i]
            // k + C[i] >= 1  =>  k >= 1 - C[i]
            L = max(L, 1 - C[i]);
        } else {          // i é par: R_i = C[i] - k
            // C[i] - k >= 1  =>  k <= C[i] - 1
            U = min(U, C[i] - 1);
        }
    }

    // Checa se as restrições batem
    if (L <= U) {
        cout << U << "\n"; // Queremos o *maior* valor possível de R1 (que é k)
    } else {
        cout << -1 << "\n"; // Impossível satisfazer todas as órbitas
    }

    return 0;
}