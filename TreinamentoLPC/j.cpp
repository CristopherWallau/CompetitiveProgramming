#include <bits/stdc++.h>
using namespace std;
#define mod 100000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second 
#define pf push_front
typedef long long ll;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int,int> pii;
void solve(vector<vi>& va,vi& ans){
    for(int i=1;i<va.size();i++){
        for(int vizinho : va[i]){
            if(vizinho>i){
                ans[i] = max(ans[i],vizinho);
        }
    }
    }
}
int main(){
    int n;
    cin >> n;
    int u=0,v=0;
    vector<vi> va(n+1);
    for(int i=0; i<n-1;i++){
        cin >> u >> v;
        va[v].push_back(u);
        va[u].push_back(v);
    }
    vi ans(n+1,0);
    solve(va,ans);
    for(int i=1; i<va.size();i++){
        cout << ans[i] << " ";
    }
}