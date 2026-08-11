#include <bits/stdc++.h>
using namespace std;    
typedef pair<int, int> ii;
typedef vector<int> vi;
int main(){
    vector<bool> vector(4, false);
    for(int i=0;i<10;i++){
        int cmp;
        cin >> cmp;
        if(cmp == 1){
            vector[0] = true;
        }
        else if(cmp == 2){
            vector[1] = true;
        }
        else if(cmp == 3){
            vector[2] = true;
        }
        else if(cmp == 4){
            vector[3] = true;
        }
    }
    int ans = 0;
    for(int i=0;i<4;i++){
        if(vector[i] == false){
            ans = ans + 1;
        }
    }
    cout << ans << "\n";
}