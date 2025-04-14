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
 * 进制转换
 * N -> 10
 * 10 -> N
 * N -> M
*/

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

// ====================================================
// convert_10_to_n ... 将10进制转成N进制
string convert_10_to_n(string& p, int b) {
    string num = p;
    string res;
    while (num != "0") {
        auto [q, r] = divide(num, b);
        res += (char)('0' + r);
        num = q;
    }
    reverse(res.begin(), res.end());
    return res;
}
void convert_10_to_n_test() {
    string num = "100";
    int b = 7;
    cout << num << "(10) " << "-> " << convert_10_to_n(num, b) << "(" << b << ")" << "\n";
}
// ====================================================



// ====================================================
// convert_n_to_10 ... 将N进制转成10进制
string convert_n_to_10(string& p, int b) {
    string num = p;
    string res;
    for (int i = 0; i < num.size(); i++) {
        res = multiply(res, b);
        res = add(res, num[i] - '0');
    }
    return res;
}
void convert_n_to_10_test() {
    string num = "202";
    int b = 7;
    cout << num << "(" << b << ")" << " -> " << convert_n_to_10(num, b) << "(10)" << "\n";
}
// ====================================================



// ====================================================
// convert_n_to_m ... 将N进制转成M进制
// 先将N进制转成10进制，再将10进制转成M进制
string convert_n_to_m(string& p, int b1, int b2) {
    string res = p;
    res = convert_n_to_10(res, b1);
    res = convert_10_to_n(res, b2);
    return res;
}
void convert_n_to_m_test() {
    string num = "202";
    int b1 = 7;
    int b2 = 8;
    cout << num << "(" << b1 << ")" << " -> " << convert_n_to_m(num, b1, b2) << "(" << b2 << ")" << "\n";
}
// ====================================================



void solve() {
    convert_10_to_n_test();
    convert_n_to_10_test();
    convert_n_to_m_test();
}

int main() {
    solve();
    return 0;
}