#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii; 
void bfs(vector<bool>& vis, int start, vector<vector<int>>& adj){
    queue<int> fila;
    fila.push(start);
    vis[start] = true;
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();

        for(int vizinho : adj[atual]){
            if(!vis[vizinho]){
                vis[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool>vis(n+1,false);
    vector<int>lideres;
    int u=0,v=0;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n;i++){
        if(!vis[i]){
        vis[i] = true;
        lideres.push_back(i);
        bfs(vis,i,adj);
        }
    }
    cout << lideres.size()-1 << "\n";
    for(int i = 1; i < lideres.size(); i++){
        cout << lideres[i-1] << " " << lideres[i] << "\n";
    }
    return 0;
}
