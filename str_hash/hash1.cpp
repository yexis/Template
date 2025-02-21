#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
#include <limits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

// 整体不右移
// ull溢出自动取模
using ull = unsigned long long;
constexpr static int N = 1e6 + 5;
struct Hash {
    vector<ull> h, f;
    ull b, m;
    Hash(string& s, ull base = 131, ull mod = 2147483647) {
        this->b = base, this->m = mod;

        int n = s.size();
        h.resize(n);
        f.resize(n);

        h[0] = 0, f[0] = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                h[i] = s[i];
                continue;
            }
            h[i] = (h[i - 1] * b % m + s[i]) % m;
            f[i] = f[i - 1] * b % m;
        }
    }
    ull get(int l, int r) {
        if (l == 0) {
            return h[r];
        }
        return (h[r] - h[l - 1] * f[r - l + 1] % m + m) % m;
    }
};

int main() {

    return 0;
}