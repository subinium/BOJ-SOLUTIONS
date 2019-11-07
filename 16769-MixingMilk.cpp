#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// C와 M 한번에 관리 
int c[3][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i = 0 ; i < 3 ; i++) for(int j = 0 ; j < 2 ; j++) cin >> c[i][j];
    for(int i = 0 ; i < 100 ; i++){
        int a = i%3;
        int b = (a+1)%3;
        int tot = c[a][1] + c[b][1]; 
        c[b][1] = min(c[b][0], tot);
        c[a][1] = tot - c[b][1];
        
    }
    for(int j = 0 ; j < 3 ; j++) cout << c[j][1] << '\n';
}