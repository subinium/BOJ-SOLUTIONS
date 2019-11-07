#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N; cin >> N;
    // 이름은 파이썬과 같지만 구현 방식(시간복잡도)이 다르지만
    // 용도는 유사하다. 중복처리 가능
    set<int> s;
    while(N--){
        int tmp; cin >> tmp;
        s.insert(tmp);
    }
    int M; cin >> M;
    while(M--){
        int tmp; cin >> tmp;
        cout << s.count(tmp) << '\n';
    }
}