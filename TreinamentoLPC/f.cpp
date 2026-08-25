#include <bits/stdc++.h>
using namespace std;
bool check(long long n, long long b) {
    vector<long long> c;
    
    // Converte para a base 'b' dígito por dígito
    while (n > 0) {
        c.push_back(n % b);
        n /= b;
    }
    
    // Checa se é palíndromo (dois ponteiros, das pontas pro meio)
    int esq = 0;
    int dir = c.size() - 1;
    while (esq < dir) {
        if (c[esq] != c[dir]) return false;
        esq++;
        dir--;
    }
    return true;
}
int main(){
    long long n;
    cin >> n;
    bool output = false;
    string c;
    long long i=n-1;
    while(i>1){
        if(i>=1000000 && (i%2 == 0)){
            if(check(i,n)){
                c.append(to_string(i));
                output = true;
                i = i/3;
            }
            i--;
        }
        else if(i>= 100000 && (i%2 != 0)){
            if(check(i,n)){
                c.append(to_string(i));
                output = true;
                i = i/2;
            }
        }
        if(check(i,n)){
                c.append(to_string(i));
                output = true;
                i--;
        }
        else{
            i--;
        }
    }
    
    if(output){
        for(char l : c){
            cout << l << " ";
        }
        cout << c[1] << " " << c[0] << "\n";
        return 0;
    }
    cout << "*" << "\n";
    return 0;
}