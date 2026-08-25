#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define debug if(DEBUG) printf
#define MAXN 200309
#define MAXM 900009
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
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
vector<bool> vis;
void bfs(int start, int target,vector<vi>& adj,vector<bool>& vis){
    int cam =0;
    queue<int> fila2;
    vector<int> parent(adj.size(),0);
    fila2.push(start);
    vis[start] = true;
    vector<int> caminho;
    while(!fila2.empty()){
        int atual = fila2.front();
        fila2.pop();
        if(atual == target){
            break;
        }
        for(int vizinho : adj[atual]){
            if(!vis[vizinho]){
                vis[vizinho] = true;
                parent[vizinho] = atual;
                fila2.push(vizinho);
            }
        }
    }
    if(!vis[target]){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    else{
        int atual = target;
        while(atual != 0){
            caminho.push_back(atual);
            atual = parent[atual];
        }
        reverse(caminho.begin(),caminho.end());
        cout << caminho.size() << "\n";
        for (int no : caminho){
            cout << no << " ";
        }
        cout << "\n";
        return;
}
}
int main(){
    int u,v,n,m;
    cin >> n >> m;
    vector<vi> adj(n+1);
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}