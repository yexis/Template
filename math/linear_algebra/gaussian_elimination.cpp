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
 * 增广矩阵
 * ans:alignas
 * 1.00 0.50 0.50 | x1 = 1.00 
 * 0.00 1.00 0.50 | x2 = 2.00 
 * 0.00 0.00 1.00 | x3 = 3.00 
 * 
 * 
 * 问题：如何判断无穷多解和无解
*/


// 以下版本只能判断方程是否具有唯一解
// 无法区分出无穷多解和无解的情况
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

// 能判断方程组具有多少解
// 返回0: 表示方程组无解
// 返回1: 表示方程组具有唯一解
// 返回2: 表示方程组具有无数解
vector<double> x;
int gauss2(vector<vector<double>> a) {
    // a是n行n+1列矩阵
    int n = a.size();
    
    // 每列的主元在哪一行
    // 即每个未知数x的主元在哪
    vector<int> where(n, -1); 

    // 遍历每列，找到其主元所在行
    for (int col = 0, row = 0; col < n && row < n; ++col) {
        // 找到当前列不为0的行
        int sel = row;
        for (int i = row; i < n; ++i) {
            if (fabs(a[i][col]) > eps) {
                sel = i;
                break;
            }
        }

        swap(a[sel], a[row]);
        if (fabs(a[row][col]) < eps) continue;
        where[col] = row;

        // 将a[row][col]变成1，同行其他元素同变
        for (int j = n; j >= col; j--) {
            a[row][j] /= a[row][col];
        }
        // 将同列其他元素变为0
        for (int i = row + 1; i < n; i++) {
            // 倒序
            for (int j = n; j >= col; j--) {
                a[i][j] -= a[i][col] * a[row][j];
            }
        }
        ++row;
    }


    // 回代
    x.assign(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (where[i] == -1) continue;
        double sum = a[where[i]][n];
        for (int j = i + 1; j < n; ++j)
            sum -= a[where[i]][j] * x[j];
        x[i] = sum / a[where[i]][i];
    }

    // 检查无解
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += x[j] * a[i][j];
        }
        if (fabs(sum - a[i][n]) > eps) {
            return 0; // 无解
        }
    }

    // 判断是否无穷多解
    for (int i = 0; i < n; ++i) {
        if (where[i] == -1) {
            return 2; // 无穷多解（自由变量）
        }
    }

    // 唯一解
    return 1;
}


// vector<double> x;
int gauss3(vector<vector<double>> a) {
    // a是n行n+1列行列式
    int n = a.size();
    
    // 如果第j列存在主元，尽量让其处于第j行

    // 即每个未知数x的主元在哪一列
    vector<int> where(n, -1); 
    // 记录第i行是否被选作主元行
    vector<int> used(n, 0);

    // 遍历每列，找到其主元所在行
    for (int i = 0; i < n; i++) {
        int to_i = i;
        for (int i1 = 0; i1 < n; i1++) {
            // 只访问没有成为主元行的行
            if (i1 != i && !used[i1] && fabs(a[i1][i]) > eps) {
                to_i = i1;
                break;
            }
        }
        if (to_i != i) swap(a[to_i], a[i]);
        if (fabs(a[i][i]) < eps) continue;
        where[i] = i; used[i] = true;

        // 将a[row][col]变成1，同行其他元素同变
        for (int j = n; j >= i; j--) {
            a[i][j] /= a[i][i];
        }
        // 将同列其他元素变为0，只消除i下面的部分
        for (int i1 = i + 1; i1 < n; i1++) {
            for (int j = n; j >= i; j--) {
                a[i1][j] -= a[i1][i] * a[i][j];
            }
        }
    }

    // 回代
    x.assign(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (where[i] == -1) continue;
        double sum = a[i][n];
        for (int j = i + 1; j < n; ++j) {
            sum -= a[i][j] * x[j];
        }
        x[i] = sum;
    }

    // 检查无解
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += x[j] * a[i][j];
        }
        if (fabs(sum - a[i][n]) > eps) {
            return 0; // 无解
        }
    }

    // 判断是否无穷多解
    for (int i = 0; i < n; ++i) {
        if (where[i] == -1) {
            return 2; // 无穷多解（自由变量）
        }
    }
    
    // 唯一解
    return 1;
}

void solve() {
    int n; cin >> n;
    vector<vector<double>> ma(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> ma[i][j];
        }
    }

    // int flg = gauss2(ma);
    // if (flg == 0) {
    //     // 无解
    //     // cout << "no answer" << "\n";
    //     cout << -1 << "\n";
    // } else if (flg == 1) {
    //     // 唯一解
    //     // cout << "unique solution" << "\n";
    //     for (int i = 0; i < n; i++) {
    //         cout << "x" << i + 1 << "=" << x[i] << "\n";
    //     }
    // } else {
    //     // 无穷多解
    //     // cout << "Infinite solutions\n";
    //     cout << 0 << "\n";
    // }

    int flg3 = gauss3(ma);
    if (flg3 == 0) {
        // 无解
        // cout << "no answer" << "\n";
        cout << -1 << "\n";
    } else if (flg3 == 1) {
        // 唯一解
        // cout << "unique solution" << "\n";
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << "=" << x[i] << "\n";
        }
    } else {
        // 无穷多解
        // cout << "Infinite solutions\n";
        cout << 0 << "\n";
    }
}

int main() {
    ios;
    cout << fixed << setprecision(20);
    solve();
    return 0;
}


/*
4
1 1 1 1 5
1 0 5 4 11 
0 0 2 3 5
0 0 9 2 11

2 
0 0 0
0 2 3

2
1 1 2
0 1 3

3
0 1 0 2
0 0 1 3
0 0 0 0
*/







