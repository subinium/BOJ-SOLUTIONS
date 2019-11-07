#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n); // n짜리 vector 선언 
    for (int i = 0; i < n; i++) cin >> v[i];
    // max_element와 min_element로 Python min, max 사용 가능
    cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
}