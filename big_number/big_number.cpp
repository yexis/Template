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


using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using puu = pair<ull, ull>;
const int dir[4][2] = {{-1, 0},
                       {1,  0},
                       {0,  -1},
                       {0,  1}};
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const string YES = "YES";
const string NO = "NO";

/*
 * 高精度 大数计算
*/


// ====================================================
// add ... 大数加x, 0 < x < 10(x为个位数)
string add(string& num, int x) {
    string res;
    int carry = x;
    for (int i = num.size() - 1; i >= 0; i--) {
        int val = (num[i] - '0') + carry;
        res.push_back((val % 10) + '0');
        carry = val / 10;
    }
    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}
void add_test() {
    string num = "12345";
    int x = 8;
    num = add(num, x);
    cout << num << "\n";
}
// ====================================================



// ====================================================
// sub ... 大数减x, 0 < x < 10(x为个位数)
string sub(string& num, int x) {
    string res = num;
    int carry = x;
    for (int i = res.size() - 1; i >= 0; i--) {
        int d = res[i] - '0';
        if (carry) {
            if (d >= carry) {
                res[i] -= carry;
                carry = 0;
            } else {
                res[i] = '0' + (10 + d) - carry;
                carry = 1;
            }
        }
    }
    return res;
}
void sub_test() {
    string num = "4444444";
    int x = 1;
    num = sub(num, x);
    cout << num << "\n";
}
// ====================================================



// ====================================================
// multiply ... 大数乘x, 0 < x < 10(x为个位数)
string multiply(string& num, int x) {
    string res;
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int d = num[i] - '0';
        int val = d * x + carry;
        res.push_back((val % 10) + '0');
        carry = val / 10;
    }
    if (carry) res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}
void multiply_test() {
    string num = "4444444";
    int x = 5;
    num = multiply(num, x);
    cout << num << "\n";
}
// ====================================================



// ====================================================
// divide ... 大数除以x, 0 < x < 10(x为个位数)
pair<string, int> divide(string& num, int x) {
    string q; int r = 0;
    for (char c : num) {
        int curr = r * 10 + (c - '0');
        q += (curr / x) + '0'; 
        r = (curr % x);
    }
    int pos = q.find_first_not_of('0');
    if (pos != string::npos) {
        q = q.substr(pos);
    } else {
        q = "0";
    }
    return make_pair(q, r);
}
void divide_test() {
    string num = "10000000000000000";
    int x = 7;
    auto [q, r] = divide(num, x);
    cout << "q:" << q << " r:" << r << "\n";
}
// ====================================================



// void solve() {
//     add_test();
//     sub_test();
//     multiply_test();
//     divide_test();
// }

// int main() {
//     solve();
//     return 0;
// }