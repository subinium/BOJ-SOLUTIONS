#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    // python dict는 C++에서 map 사용
    // 구현 방식은 다르지만 사용방법은 동일
    // key, value의 자료형을 지정해줘야 사용할 수 있음
    map<string, string> mp;
    map<string, set<string>> mps;
    for(int i = 0 ; i < n ; i++){
        string team; int k; cin >> team >> k;
        for(int j = 0 ; j < k ; j++){
            string name; cin >> name;
            mps[team].insert(name);
            mp[name] = team;
        }
    }

    while(m--){
        int k; string q; cin >> q >> k;
        if(k==0){
            // auto는 자동 형맞춤, 보통은 구체적인 자료형을 사용하는 것을 추천
            for(auto i : mps[q]) cout << i << '\n';
        }
        else cout << mp[q] << '\n';
    }
}
