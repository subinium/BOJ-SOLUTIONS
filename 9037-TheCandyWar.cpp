#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// 동일 비교
bool same(vector<int>& v){
    auto f = v[0];
    for(auto i : v) if(f!=i) return false;
    return true;
}

// 나눠주기
void circle(vector<int>& v){
    vector<int> vv;
    for(auto i : v) vv.push_back(i/2);
    for(int i = 0 ; i < v.size()-1 ; i++){
        v[i+1] = v[i+1]/2 + vv[i];  
    }
    v[0] = v[0]/2 + vv[v.size()-1];
    for(auto &i : v) if(i&1) i++;
}

// 입력 개수만큼 반복
void process(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        if(v[i]&1) v[i]++;
    }
    int cnt = 0; 
    while(!same(v)){
        circle(v);
        cnt++;
    }
    cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) process();  
}