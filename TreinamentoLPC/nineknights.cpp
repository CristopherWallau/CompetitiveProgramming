#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
#define debug if(DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
#define mod 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238462643383279502884
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pf push_front
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define mset(x,y) memset(x,y,sizeof(x))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int,int> pii;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
vector<string> grid;
int x=0,y=0;
bool isValid(int x, int y) {
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    grid.resize(5);
    for(int i=0; i<5;i++){
        cin >> grid[i];
    }
    int count =0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(grid[i][j] == 'k'){
                count++;
                for(int k=0;k<8;k++){
                    int nx= i+dx[k];
                    int ny= j+dy[k];
                    if(isValid(nx,ny) && grid[nx][ny] == 'k'){
                        cout << "invalid\n";
                        return 0;
                    }
                }
            }
        }
    }
    if(count != 9){
        cout << "invalid\n";
        return 0;
    }else{
    cout << "valid\n";
}
return 0;
}