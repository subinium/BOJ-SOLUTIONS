#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N; string S; cin >> N >> S;
    int score = 0, bonus = 0;
    // C++11에서는 tuple 사용이 불편하여 따로 처리하는 것을 추천
    for(int i = 0 ; i < N ; i++){ 
        if(S[i]=='O'){
            score += i+1+bonus;
            bonus += 1;
        }
        else bonus = 0;
    }
    cout << score;

}