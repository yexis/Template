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
#include <climits>

using namespace std;
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define next_per next_permutation
#define call(x) (x).begin(), (x).end()
#define debug(x) cerr << (#x) << " = " << (x) << endl;
#define debugout(x) cout << (#x) << " = " << (x) << endl;
#define debugerr(x) cerr << (#x) << " = " << (x) << endl;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pbi = pair<bool, int>;
using pib = pair<int, bool>;
using pis = pair<int, string>;
using psi = pair<string, int>;
using puu = pair<ull, ull>;
using arr = array<int, 3>;
using arr3 = array<int, 3>;
using arr4 = array<int, 4>;
using arr5 = array<int, 5>;

const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

ll power(ll x, ll b, ll m = mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans *= x;
            ans %= m;
        }
        x *= x;
        x %= m;
        b >>= 1;
    }
    return ans;
}

/*
 * 高斯消元 求解方程组 
 * 讲解：https://www.bilibili.com/video/BV1Kd4y127vZ/?spm_id_from=333.1387.search.video_card.click&vd_source=a5e205ce7c5908e561eb8023831ffff2
 * 现将矩阵转化成上三角的矩阵，然后逆推得出结果
 * 
 * ma:
 * 0 2 1 | 7
 * 2 1 1 | 7
 * 2 2 1 | 9
 * 
 * ans:alignas
 * 1.00 0.50 0.50 | x1 = 1.00 
 * 0.00 1.00 0.50 | x2 = 2.00 
 * 0.00 0.00 1.00 | x3 = 3.00 
*/
const double eps = 0.00000001;
bool gauss(vector<vector<double>>& ma) {
    // ma: 增广矩阵，包含a和b
    int n = ma.size();
    for (int i = 0; i < n; i++) { // 枚举每行
        int to_i = i;
        for (int ii = i; ii < n; ii++) {
            if (fabs(ma[ii][i]) > eps) {
                to_i = ii; 
                break;
            }
        }
        if (to_i != i) swap(ma[i], ma[to_i]); // 交换两行
        if (fabs(ma[i][i]) < eps) return false; // 无解

        // 将ma[i][i]变成1，同行其他元素同变
        for (int j = n; j >= i; j--) {
            ma[i][j] /= ma[i][i]; 
        }

        // 将同列其他元素变为0
        for (int ii = i + 1; ii < n; ii++) {
            for (int j = n; j >= i; j--) {
                ma[ii][j] -= ma[ii][i] * ma[i][j];
            }
        }
    }

    // 回代求解
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ma[i][n] -= ma[i][j] * ma[j][n];
        }
    }
    return true;
}

int main() {
    ios;
    cout << fixed << setprecision(2);
    vector<vector<double>> ma = {
      {0, 2, 1, 7},  
      {2, 1, 1, 7},  
      {2, 2, 1, 9},  
    };
    bool flg = gauss(ma);
    if (flg) {
        for (auto& es : ma) {
            for (auto& e : es) {
                cout << e << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "no answer" << "\n";
    }
    return 0;
}









