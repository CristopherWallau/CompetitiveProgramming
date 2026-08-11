#include <bits/stdc++.h>
using namespace std;

// Tudo como long long para blindar contra overflow
bool bin(long long mid, long long t, vector<long long> &k){
    long long total_produtos = 0;
    for(int i = 0; i < k.size(); i++){
        total_produtos += mid / k[i];
        if(total_produtos >= t){
            return true;
        }
    }
    return false;
}

int main(void){
    // Otimização de input (sempre bom deixar no template!)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t;
    cin >> n >> t;
    
    vector<long long> k(n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    
    long long L = 0;
    long long R = 1e18;
    long long ans = R;
    
    while(L <= R){
        long long mid = L + (R - L) / 2;
        
        if(bin(mid, t, k)){
            ans = mid;
            R = mid - 1;
        }
        else{
            L = mid + 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}