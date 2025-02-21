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

// 为什么这里用array要比vector快
using ull = unsigned long long;
using puu = pair<ull, ull>;
constexpr static int N = 1e6 + 5;
struct Hash {
    vector<array<ull, 2>> h, f;
    ull b1, m1;
    ull b2, m2;
    Hash(string& s, int base1 = 131, int mod1 = 2147483647, int base2 = 13331, int mod2 = 1000000007) {
        this->b1 = base1;
        this->m1 = mod1;
        this->b2 = base2;
        this->m2 = mod2;

        int n = s.size();
        h.resize(n);
        f.resize(n);

        h[0][0] = h[0][1] = 0;
        f[0][0] = f[0][1] = 1;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                h[i][0] = h[i][1] = s[i];
                continue;
            }
            h[i][0] = (h[i - 1][0] * b1 % m1 + s[i]) % m1;
            h[i][1] = (h[i - 1][1] * b2 % m2 + s[i]) % m2;
            f[i][0] = f[i - 1][0] * b1 % m1;
            f[i][1] = f[i - 1][1] * b2 % m2;
        }
    }
    puu get(int l, int r) {
        if (l == 0) {
            return {h[r][0], h[r][1]};
        }
        return {
                (h[r][0] - h[l - 1][0] * f[r - l + 1][0] % m1 + m1) % m1,
                (h[r][1] - h[l - 1][1] * f[r - l + 1][1] % m2 + m2) % m2
        };
    }
};

int main() {

    return 0;
}