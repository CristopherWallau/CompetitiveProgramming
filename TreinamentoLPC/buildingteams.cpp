#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii; 
vector<bool> vis;
vector<vi> adj;
bool bfs(vector<bool>& vis, int start, vector<vector<int>>& adj, vector<int>& teams){
    queue<int> fila;
    fila.push(start);
    vis[start] = true;
    teams[start] = 1;
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        for(int vizinho : adj[atual]){
            if(teams[vizinho] == 0 && !vis[vizinho] && teams[atual] == 1){
                teams[vizinho] = 2;
                vis[vizinho] = true;
                fila.push(vizinho);
            }
            else if(teams[vizinho] == 0 && !vis[vizinho] && teams[atual] == 2){
                teams[vizinho] = 1;
                vis[vizinho] = true;
                fila.push(vizinho);
            }
            else if(teams[vizinho] == teams[atual]){
                cout << "IMPOSSIBLE" << "\n";
                return false;
            }
        }
    
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vis.resize(n+1,false);
    adj.resize(n+1);
    vector<int> teams(n+1,0);
    int u=0,v=0;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
                if(!vis[i]){
                    vis[i] = true;
                    if(!bfs(vis,i,adj,teams)) return 0;
                }
    }
    for(int i=1; i<teams.size();i++){
        cout << teams[i] << " ";
    }
    cout << "\n"; // Imprime a resposta
    return 0;
}