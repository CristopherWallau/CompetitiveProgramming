#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // Data de exemplo da sua imagem: 9 de Agosto de 2010
    int day = 0;
    int month = 0;
    int year = 0;
    cin >> day >> month >> year;
    // 1. Configurando a estrutura de tempo (struct tm)
    struct tm past_date = {0}; // Inicializa tudo com zero para evitar lixo de memória
    
    past_date.tm_mday = day;
    
    // ATENÇÃO AOS "PEGAS" DO C++ AQUI:
    past_date.tm_mon = month - 1;    // Os meses vão de 0 (Jan) a 11 (Dez)
    past_date.tm_year = year - 1900; // O ano é contado a partir de 1900!

    // mktime() converte o struct tm para time_t (segundos) e, de quebra,
    // preenche automaticamente o dia da semana (tm_wday) na nossa past_date.
    time_t past_time = mktime(&past_date);

    // 2. Descobrindo o dia da semana
    // O tm_wday retorna um int de 0 a 6, onde 0 = Domingo, 1 = Segunda...
    string days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    cout << "The date " << day << "/" << month << "/" << year << " is a " 
         << days_of_week[past_date.tm_wday] << ".\n";

    // 3. Calculando os dias decorridos até o presente
    time_t now = time(nullptr); // Pega o timestamp exato do momento em que o código roda
    
    // difftime() retorna a diferença entre dois tempos em segundos
    double seconds_elapsed = difftime(now, past_time);
    
    // Converte os segundos para dias (60s * 60m * 24h = 86400 segundos em um dia)
    long long days_elapsed = seconds_elapsed / 86400;

    cout << "Days elapsed until present: " << days_elapsed << " days.\n";

    return 0;
}