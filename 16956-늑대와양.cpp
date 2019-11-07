#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char arr[505][505];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int R, C; cin >> R >> C;
  for(int i = 1 ; i <= R ; i++){
    for(int j = 1 ; j <= C ; j++){
      cin >> arr[i][j];
    }
  }
  
  for(int i = 1 ; i <= R ; i++){
    for(int j = 1 ; j <= C ; j++){
      if(arr[i][j]=='.'||arr[i][j]=='D') continue;
      if(arr[i][j]=='W'){
        for(int x = 0 ; x < 4 ; x++){
          int ii = i + dx[x], jj = j + dy[x];
          if(arr[ii][jj]=='S'){
            cout << 0;
            return 0;
          }
        }
      }
    }
  }

  cout << 1 << '\n';
  for(int i = 1 ; i <= R ; i++){
    for(int j = 1 ; j <= C ; j++) {
      if(arr[i][j]=='.') cout << 'D';
      else cout << arr[i][j];
    }
    cout << '\n';
  }
}