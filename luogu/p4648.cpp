//
// Created by yex on 2024/4/3.
//


#include <iostream>
#include <vector>
#include <tuple>
#include <array>
using namespace std;
using ll = long long;

ll cal1(vector<int>& v, ll D) {
    int n = v.size();
    ll ans = 0;
    sort(v.begin(), v.end());
    int l = 0, r = 0;
    while (r < n) {
        while (l <= r && v[r] - v[l] > D) {
            l++;
        }
        ans += r - l;
        r++;
    }
    return ans;
}

struct BIT {
    int n;
    vector<int> tr;
    BIT(int nn) {
        n = nn;
        tr.resize(n + 1);
    }
    int lb(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lb(i)) {
            tr[i] += u;
        }
    }
    ll ask(int x) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            ans += tr[i];
        }
        return ans;
    }
};

ll cal2(vector<pair<int, int>>& _v, ll D) {
    int n = _v.size();
    ll ans = 0;

    vector<pair<int, int>> v;
    for (auto [x, y] : _v) {
        v.push_back(make_pair(x + y, x - y));
    }
    sort(v.begin(), v.end());

    const int M = 75000;
    const int N = M * 2 + 5;
    BIT bit(N);

    int l = 0, r = 0;
    while (r < n) {
        while (l <= r && v[r].first - v[l].first > D) {
            bit.add(v[l].second + 1, -1);
            l++;
        }

        auto [_, y] = v[r];
        ans += bit.ask(y + D + 1) - bit.ask(max(y - D - 1 + 1, 0ll));
        bit.add(y + 1, 1);
        r++;
    }
    return ans;
}

ll cal3(vector<array<int, 3>>& v, ll D) {
    int n = v.size();
    ll ans = 0;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {

    }

    return ans;
}

int main() {
    vector<int> a;
    vector<pair<int, int>> aa;
    vector<array<int, 3>> aaa;
    ll B, N, D, M, ans;
    cin >> B >> N >> D >> M;
    if (B == 1) {
        int x;
        for (int i = 0; i < N; i++) {
            cin >> x;
            a.push_back(x);
        }
        ans = cal1(a, D);
    } else if (B == 2) {
        int x, y;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            aa.push_back(make_pair(x, y));
        }
        ans = cal2(aa, D);
    } else if (B == 3) {
        int x, y, z;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> z;
            aaa.push_back(array<int, 3>{x, y, z});
        }
        ans = cal3(aaa, D);
    }
    cout << ans << endl;
    return 0;
}
