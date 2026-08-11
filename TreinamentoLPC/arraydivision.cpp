#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define debug if(DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
#define mod 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238462643383279502884
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pf push_front
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define mset(x,y) memset(x,y,sizeof(x))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool check(ll mid, vector<ll>& a, int k){
    ll soma_atual =0;
    int pedaços =1;
    for(int i = 0; i < a.size(); i++){
        if(soma_atual + a[i] > mid){
            pedaços++;
            soma_atual = a[i];
        } else{
            soma_atual += a[i];
        }
    }
    return pedaços <= k;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<ll> a(n);
    ll total_sum = 0;
    ll minmaxsome = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        total_sum += a[i];
        minmaxsome = max(minmaxsome, a[i]);
    }

    if (k == 1 || n == 1) {
        cout << total_sum << "\n";
        return 0;
    }

    ll L = minmaxsome;  
    ll R = total_sum;   
    ll ans = R;         

    while(L <= R){
        ll mid = L + (R - L) / 2;

        if(check(mid, a, k)){
            ans = mid;    
            R = mid - 1;  // Apertamos a busca para tentar achar um teto ainda menor.
        } else {
            L = mid + 1;  // Teto muito baixo (gerou pedaços demais), precisamos aumentar.
        }
    }

    // 8. Saída final
    cout << ans << "\n";
    
    return 0;
}