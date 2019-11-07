#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int n, v[11][11];

int ck(vector<int> x){
  int ret = 0;
  set<int> s;
  for(auto q : x){
    int i = q/n, j = q%n;
    ret += v[i][j];
    s.insert(q);
    for(int w = 0 ; w < 4 ; w++){
      int ii = i + dx[w], jj = j + dy[w];
      if(ii < 0 || ii >= n || jj < 0 || jj >= n) return 4000;
      ret += v[ii][jj];
      s.insert(ii*n+jj);
    }
  }

  if(s.size()!= 15) return 4000;
  return ret;
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      cin >> v[i][j];
    }
  }
  int ans = 4000;
  for(int i = 0 ; i < n*n ; i++){
    for(int j = i+1 ; j < n*n ; j++){
      for(int k = j+1 ; k < n*n ; k++){
        vector<int> x = {i, j, k};
        ans = min(ck(x), ans);
      }
    }
  }
  cout << ans;
}