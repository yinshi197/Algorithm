#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define int long long
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 2e5 + 10, M = 1e8 + 10;

int n, k, a[N]; 

bool check2 (int val, int z) {
    int cnt = 0;
    if (z == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] <= val) {
                if (i != n) cnt += 2;
                else cnt++;
                i++;
            }
        }
    }
    else {
        cnt++;
        for (int i = 2; i <= n; i++) {
            if (a[i] <= val) {
                if (i != n) cnt += 2;
                else cnt++;
                i++;
            }
        }
    }
    return cnt >= k;
}

bool check (int val) {
    if (check2(val, 0) || check2(val, 1)) return true;
    return false;
}

void solve() {
    cin >> n >> k;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; r = max(r, a[i]);
    }
    while (l != r - 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid; 
    }
    cout << r << "\n";
}  

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}