#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; // Padrão da SBC para respostas gigantes

int main(){
    // Otimização sagrada de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> v(n + 2);
    for(int i = 1; i <= n + 1; i++){
        cin >> v[i];
    }

    // Caso base: polinômio P(x) = 1 (grau 0)
    if(n == 0){
        cout << 0 << "\n";
        return 0;
    }

    // Pré-calculando as potências de 2 módulo 10^9+7
    vector<long long> p2(n + 1, 1);
    for(int i = 1; i <= n; i++){
        p2[i] = (p2[i-1] * 2) % MOD;
    }

    long long odd_steps = 0;
    int zeros = 0;
    bool first = false;

    // Começamos a olhar do v[2] (que é o coeficiente de x^{n-1})
    for(int i = 2; i <= n + 1; i++){
        int b = v[i];
        if(b == 0){
            zeros++;
        } else { // Achamos um bit 1
            if(!first){
                odd_steps = (odd_steps + p2[zeros]) % MOD;
                first = true;
            } else if(zeros > 0){
                odd_steps = (odd_steps + p2[zeros]) % MOD;
            }
            zeros = 0; // reseta o contador de zeros
        }
    }

    // Cada passo ímpar na verdade engloba 2 passos no jogo da Aline
    // E os divisões por X (passos pares) acontecem exatamente N vezes.
    long long ans = (2 * odd_steps + n) % MOD;
    
    cout << ans << "\n";

    return 0;
}