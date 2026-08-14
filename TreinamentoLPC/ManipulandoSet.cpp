#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> a;
    int x = 0;
    for(int i =0;i<n;i++){
        cin >> x;
        a.insert(x);
    }
    for(int n : a){
        cout << n << " ";
    }
    return 0;
}