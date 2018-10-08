#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

struct matrix{
    int N;
    ll A[82][82];
    matrix(int n){
        N = n;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                A[i][j] = 0;
            }
        }
    }

    matrix operator +(matrix t){
        matrix res(N);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                res.A[i][j] = (A[i][j] + t.A[i][j]) % mod;
            }
        }
        return res;
    }

    matrix operator *(matrix t){
        matrix res(N);
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                for (int k=0;k<N;k++){
                    res.A[i][j] = (res.A[i][j] + A[i][k] * t.A[k][j]) % mod;
                }
            }
        }
        return res;
    }
};

ll bi[44][44];

int main(){
    ll N; int K; cin >> N >> K;
    for (int i = 0 ; i <= K ; i++){
        bi[i][0] = bi[i][i] = 1;
        for (int j = 1 ; j < i ;j++) bi[i][j] = (bi[i-1][j-1] + bi[i-1][j]) % mod;
    }

    matrix A(2*(K+1)+1);
    for (int i = 0 ; i <= K ; i++){
        for (int j = i ; j <= K ; j++){
            A.A[i][j+K+1] = A.A[i+K+1][j] = A.A[i+K+1][j+K+1] = bi[j][i];
        }
    }
    A.A[2*K+2][2*K+2] = A.A[2*K+1][2*K+2] = 1;

    matrix R(2*(K+1)+1);
    for(int i = 0 ; i <= 2*K+2 ; i++) R.A[i][i] = 1;

    while (N){
        if (N & 1) R = R * A;
        A = A * A;
        N >>= 1;

    }
    ll ans = 0;
    for (int i = 0 ; i < 2*K+2 ; i++) ans = (ans + R.A[i][2*K+2]) % mod;
    cout << ans;
}
