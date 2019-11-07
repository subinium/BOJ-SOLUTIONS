#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// easy와 hard를 배열로 구현
int ck[2];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N, L, K; cin >> N >> L >> K;
    for(int i = 0 ; i < N ; i++){
        int a, b; cin >> a >> b;
        if(b <= L) ck[0]++;
        else if(a <= L) ck[1]++;
    }
    // 예외처리 없이 한줄로 처리 가능
    cout << 140 * min(K, ck[0]) + 100 * min(ck[1], max(K-ck[0], 0)); 
}
