#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n; cin >> n; 
    vector<long long> v(n+1); // int overflow가 날 수 있으니 long long 사용
    for (int i = 1; i <= n; i++) cin >> v[i];
    // sum 관련 함수가 따로 없으니 평균을 이용해 합을 구하는 방식
    for (int i = 1; i <= n; i++) cout << v[i]*i-v[i-1]*(i-1) << '\n';
    
}