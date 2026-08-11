#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m){
    if(n >=m){
        return n-m;
    }
    if(m % 2 == 0){
    int mid = m/2;
        return 1 + solve(n,mid);
    }
    else{
        return 1 + solve(n,m+1);
    }
}
int main() {
    // Otimização de entrada e saída para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    int n,m;
    cin >> n >> m; // Leitura do número de casos de teste

    ans = solve(n,m);
    cout << ans <<"\n";
    
    return 0;
}