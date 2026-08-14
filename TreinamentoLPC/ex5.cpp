#include <bits/stdc++.h>
using namespace std;
struct Pessoa{
    int dia;
    int mes;
    int ano;
};
bool dayCmp(Pessoa a, Pessoa b){
    if(a.dia < b.dia) return true;
    else 
        return false;
}
int main(){
    int n;
    cin >> n;
    vector<Pessoa> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].dia >> a[i].mes >> a[i].ano;
    }
    sort(a.begin(),a.end(),dayCmp);
    for(Pessoa x : a){
        cout << x.dia << x.mes << x.ano;
    }
}