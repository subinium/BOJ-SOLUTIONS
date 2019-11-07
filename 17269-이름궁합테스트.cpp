#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};


// 마지막에 남은 길이를 더 해주는 것은 차이가 있어
// 길이가 남은 스트링의 문자를 붙여주는 방식으로 사용
string f(string a, string b){
    string ret;
    for(int i = 0 ; i < min(a.size(), b.size()) ; i++){
        ret += a[i];
        ret += b[i];
    }
    if(a.size()>b.size()) for(int i = b.size() ; i < a.size() ; i++) ret += a[i];
    else for(int i = a.size() ; i < b.size() ; i++) ret += b[i];
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int A, B; string As, Bs; cin >> A >> B >> As >> Bs;
    string x = f(As, Bs); // 합치는 과정을 함수로 만듬
    vector<int> v;
    for(auto i : x) v.push_back(cnt[i-'A']); 
    for(int i = 0 ; i < A+B-2 ; i++){
        for(int j = 0 ; j < A+B-i-1 ; j++ ){
            v[j] = (v[j]+v[j+1])%10; // %10은 안해줘도 무방
        }
    }
    cout << v[0]*10+v[1] << '%';
}