#include <bits/stdc++.h>
using namespace std;

// Função mágica que verifica se a altura H é possível
bool check(long long H, const vector<long long>& x, long long K, int N) {
    long long max_L = 1; // O reforço tem que cair pelo menos no índice 1
    long long min_R = N; // E no máximo no índice N

    for (int j = 1; j <= N; j++) {
        if (x[j] < H) {
            long long req = H - x[j];
            
            // Se um bloco precisa de mais do que o reforço máximo K, já é impossível
            if (req > K) return false; 

            long long L_j = j;
            long long R_j = j + K - req;

            // Atualiza a intersecção global de onde o reforço pode cair
            max_L = max(max_L, L_j);
            min_R = min(min_R, R_j);
        }
    }
    
    // Se o maior limite inferior ainda for menor ou igual ao menor limite superior,
    // significa que existe pelo menos um índice 'i' válido onde colocar o reforço!
    return max_L <= min_R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    if (!(cin >> N >> K)) return 0;

    // Usando 1-index para facilitar o acompanhamento da fórmula
    vector<long long> x(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    // Busca binária na resposta
    long long L = 1;
    // O maior bloco possível tem altura 10^9 e pode receber +10^5
    long long R = 2e9; 
    long long ans = 1;

    while (L <= R) {
        long long mid = L + (R - L) / 2;

        if (check(mid, x, K, N)) {
            ans = mid;     // A altura 'mid' é possível. Salva ela!
            L = mid + 1;   // Vamos ser ambiciosos e tentar uma altura maior
        } else {
            R = mid - 1;   // Fomos longe demais, precisamos tentar uma altura menor
        }
    }

    cout << ans << "\n";
    return 0;
}