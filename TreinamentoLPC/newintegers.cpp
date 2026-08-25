#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin >> t;    
    string test_case;
    for(int i=0;i<t;i++){
        cin >> test_case;
        int n;
        cin >> n; // Lê a quantidade de elementos que o problema avisa que tem

        string array_str;
        cin >> array_str; // Vai ler a string inteira "[1,2,3,5,8]" ou "[]"

        deque<int> dq;
        string num_atual = "";

        // Varre a string da esquerda pra direita
        for (char c : array_str) {
            if (isdigit(c)) {
            // Se for número, vai acumulando (pra não quebrar números grandes como "42")
            num_atual += c; 
            } 
            else if (c == ',' || c == ']') {
            // Se bateu numa vírgula ou fechou o colchete, o número acabou!
                if (!num_atual.empty()) {
                    dq.push_back(stoi(num_atual)); // stoi = String TO Integer
                    num_atual = ""; // Limpa a variável para o próximo número da fila
                }
            }
        }
        bool invertido = false;
        bool error = false;
        for(char c : test_case){
            if(c == 'R'){
                invertido = !invertido;
            }
            else if(c =='D'){
                if(!invertido && (!dq.empty())){
                    dq.pop_front();
                }
                else if(invertido && (!dq.empty())){
                    dq.pop_back();
                }
                else{
                    cout << "error" << "\n";
                    error = true;
                    break;
                }
            }
        }
        if(!error){
            cout <<"[";
            if(!dq.empty()){
                if(!invertido){
                    // Imprime até o PENÚLTIMO (size - 1)
                    for(int i = 0; i < (int)dq.size() - 1; i++){
                        cout << dq[i] << ",";
                    }
                    cout << dq[dq.size()-1]; // Último sem vírgula
                }else {
                    // Imprime até o SEGUNDO elemento (índice 1, ou seja, i > 0)
                    for(int i = dq.size() - 1; i > 0; i--){
                        cout << dq[i] << "," ;
                    }
                    cout << dq.front(); // Primeiro elemento sem vírgula
                }
            }
            
            cout << "]\n"; // Fecha o colchete depois de tudo
        }
    } // Fim do laço dos test_cases
} // Fim da main