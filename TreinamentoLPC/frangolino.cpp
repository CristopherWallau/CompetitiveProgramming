#include <bits/stdc++.h>
using namespace std;    
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(q);
    for(int i=0;i<q;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=0;i<q;i++){
        if(v[i] > ans + 1){
            break;
        }
        ans = ans + v[i];
    }
    for(int i=0;i<n;i++){
        if(v[i] == ans + 1){
            cout << ans + 2 << "\n";
            return 0;
        }
    }
}