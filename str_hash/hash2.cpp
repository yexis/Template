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

// 整体右移一位
namespace HASH2_1 {
    const int maxn = 1e5;
    const int base = 131; // or 13331
    ull f[maxn + 10], h[maxn + 10];
    void init(string& s) {
        int n = s.size();
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * base + s[i];
            f[i] = f[i] * base;
        }
    }
    ll get(int l, int r) {
        return h[r] - h[l - 1] * f[r - l + 1];
    }
}

int main() {

    return 0;
}