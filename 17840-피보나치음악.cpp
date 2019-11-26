#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ck[1005][1005];
string S;

ll preprocessing(int mod) {
    int fi = 1, se = 1;
    int L = 0;
    for (int i = 1;; i++) {
        if (ck[fi][se]) {
            return S.size() + to_string(fi).size() - ck[fi][se];
        }
        string s = to_string(fi);
        S += s;
        L += s.size();
        ck[fi][se] = L;
        int tmp = se;
        se = (fi + se) % mod;
        fi = tmp;
    }
    return -1;
}

char query(ll N, ll L) {
    if (N <= S.size()) return S[N - 1];
    ll tmp = N - S.size();
    N -= (tmp + L - 1) / L * L;
    return S[N - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M, Q;
    cin >> Q >> M;

    ll L = preprocessing(M);
    cout << S << endl;
    while (Q--) {
        ll N;
        cin >> N;
        cout << query(N, L) << '\n';
    }
}
