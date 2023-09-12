#include <iostream>
#include <string>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

namespace NUMDP_1 {
    int f[1000][1000];
    int m;
    string s;
    void init(int num) {
        s = to_string(num);
        m = s.size();
    }
    int dfs(int i, int mask, int is_limit, int is_num) {
        if (i == m) {
            return is_num;
        }
        if (f[i][mask] >= 0) {
            return f[i][mask];
        }
        int res = 0;
        if (!is_num) {
            res = dfs(i + 1, mask, false, false);
        }
        int up = is_limit ? s[i] - '0' : 9;
        for (int j = is_num ? 0 : 1; j <= up; j++) {
            // judge
            res += dfs(i + 1, mask, is_limit && j == up, true);
        }
        return f[i][mask] = res;
    }
}

namespace NUMDP_2 {
    int f[1000][1000];
    int m;
    string s;
    void init(int x) {
        s = to_string(x);
        m = s.size();
    }
    int dfs(int i, int mask, int is_limit, int is_num) {
        if (i == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[i][mask]) {
            return f[i][mask];
        }
        int res = 0;
        if (!is_num) {
            res = dfs(i + 1, mask, false, false);
        }
        int up = is_limit ? s[i] - 'a' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                res += dfs(i + 1, mask | (1 << d), is_limit && d == up, true);
            }
        }

        return f[i][mask] = res;
    }
}

namespace NUMDP_3 {
    int f[1000][1000];
    int m;
    string s;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        int ans = 0;
        if (!is_num) {
            ans += dfs(pos + 1, mask, false, false);
        }

        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask, is_limit && d == up, true);
        }

        return f[pos][mask] = ans;
    }
}

namespace NUMDP_4 {
    int f[12][1<<12];
    int m;
    string s;
    void init(int x) {
        memset(f, -1, sizeof(f));
        s = to_string(x);
        m = s.size();
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return !is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        int ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
        }
        return ans = f[pos][mask];
    }
}

namespace NUMDP_5 {
    int f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        int ans = 0;
        if (!is_num) {
            ans += dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_6 {
    int f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_7 {
    int f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_8 {
    int f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans += dfs(pos + 1, mask, false, false);
            ans %= mod;
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_9 {
    int f[12][1 << 12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (f[pos][mask] != -1 && !is_limit && is_num) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_10 {
    int f[12][1 << 12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_11 {
    int f[12][1 << 12];
    string s;
    int m;
    void init(int x) {
        memset(f, -1, sizeof(f));
        s = to_string(x);
        m = s.size();
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        int ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0': 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | (1 << d), is_limit && d == up, true);
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_12 {
    int f[12][1 << 12];
    string s;
    int m;
    void init(int x) {
        memset(f, -1, sizeof(f));
        s = to_string(x);
        m = s.size();
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (not is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (not is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask & 1 << d) {
                continue;
            }
            ans += dfs(pos + 1, mask | 1 << d, is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_13 {
    int f[12][1 << 12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return 1;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        int ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | 1 << d, is_limit && d == up, true);
            ans %= mod;
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_14 {
    int f[12][1 << 12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    int dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (f[pos][mask] != -1) {
            return f[pos][mask];
        }

        ll ans = 0;
        if (!is_num) {
            dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | 1 << d, is_limit && d == up, true);
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_15 {
    int f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
    }
    ll dfs(int idx, int mask, int is_limit, int is_num) {
        if (idx == m) {
            return 1;
        }
        if (f[idx][mask] != -1) {
            return f[idx][mask];
        }
        ll ans = dfs(idx + 1, mask, false, false);
        int up = is_limit ? s[idx] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(idx + 1, mask | 1 << d, is_limit && d == up, true);
        }
        return f[idx][mask] = ans;
    }
}

namespace NUMDP_16 {
    int f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        memset(f, -1, sizeof(f));
        s = to_string(x);
        m = s.size();
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask] != -1) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | 1 << d, is_limit && d == up, true);
        }
        return f[pos][mask] = ans;
    }
}

namespace NUMDP_17 {
    ll f[12][1<<12];
    string s;
    int m;
    void init(int x) {
        s = to_string(x);
        m = s.size();
        memset(f, -1, sizeof(f));
    }
    ll dfs(int pos, int mask, int is_limit, int is_num) {
        if (pos == m) {
            return is_num;
        }
        if (!is_limit && is_num && f[pos][mask]) {
            return f[pos][mask];
        }
        ll ans = 0;
        if (!is_num) {
            ans = dfs(pos + 1, mask, false, false);
        }
        int up = is_limit ? s[pos] - '0' : 9;
        int d = is_num ? 0 : 1;
        for (; d <= up; d++) {
            if (mask >> d & 1) {
                continue;
            }
            ans += dfs(pos + 1, mask | 1 << d, is_limit && d == up, true);
        }
        return f[pos][mask] = ans;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
