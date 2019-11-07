#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    // C++에서 클래스로 선언된 자료형은 모두 초기값이 0 또는 빈 값입니다.
    // 따로 대입하여 초기화 시킬 필요는 없습니다.
    string S, tmp, ans; 
    // 공백이 있는 문자열은 getline으로 받으면 됩니다.
    getline(cin, S);
    bool ck = false;
    
    for(auto i : S){
        if(i == ' '){
            if (!ck) {
                reverse(tmp.begin(), tmp.end());
                ans += tmp + ' ';
                tmp = ""; 
            }
            else ans += ' ';
        }
        else if(i == '<'){
            ck = true;
            reverse(tmp.begin(), tmp.end());
            ans += tmp + '<';    
            tmp = "";
        }
        else if(i == '>'){
            ck = false;
            ans += '>';
        }
        else {
            if(ck) ans += i;
            else tmp += i;
        }
    }
    reverse(tmp.begin(), tmp.end());
    ans += tmp;
    cout << ans;

}