#include <bits/stdc++.h>
using namespace std;

// find를 사용하는 것보다 그냥 구현하는 것이 간단합니다.

bool win(char a, char b){
  if((a=='S'&&b=='P') || (a=='P'&&b=='R') || (a=='R'&&b=='S')) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  char ML, MR, TL, TR;
  cin >> ML >> MR >> TL >> TR;
  if(ML!=MR && TL!=TR) cout << '?';
  else if(ML==MR && TL!=TR) {
    if(win(TL, ML) || win(TR, ML)) cout << "TK";
    else cout << '?';
  }
  else if(ML!=MR && TL==TR) {
    if(win(ML, TL) || win(MR, TL)) cout << "MS";
    else cout << '?';
  }
  else{
    if(win(ML, TL)) cout << "MS";
    else if(win(TL, ML)) cout << "TK";
    else cout << '?';
  }
}
