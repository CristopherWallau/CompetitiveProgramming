#include <bits/stdc++.h>
using namespace std;    
typedef pair<int, int> ii;
typedef vector<int> vi;
int main(){
    int n,m;
    cin >> n >> m;
    int tam = max(n,m);
    vector<int> max_class(tam + 1, 0);
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> v[i][j];
            max_class[j] = max(max_class[j], v[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=tam;i++){
        ans = ans + max_class[i];
    }
    cout << ans << "\n";
    
}