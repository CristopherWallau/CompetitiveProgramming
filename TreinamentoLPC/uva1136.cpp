#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    multiset<int> ms;
    int x;
    long long soma =0;
    while(cin >> n && n != 0){
        soma =0;
        multiset<int> ms;
        for(int i=0;i<n;i++){
            int k;
            cin >> k;
            for(int j=0;j<k;j++){
                cin >> x;
                ms.insert(x);
            }
            int maior = *ms.rbegin();
            int menor = *ms.begin();
            soma += maior-menor;
            if(!ms.empty()){
                ms.erase(ms.begin());
            }
            if(!ms.empty()){
                ms.erase(prev(ms.end()));
            }
        }
        cout << soma <<"\n";
    }
return 0;
}