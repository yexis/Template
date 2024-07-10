//
// Created by yex on 2023/3/26.
//
#include "../../sum.h"
#include "functional"

int main() {
    using ll = long long;
    vector<vector<ll>> dp(10, vector<ll>(10, 0));
    function<long long(int, int)> dfs = [&](int r, int c) {
        if (r == 0 || c == 0) {
            return 0ll;
        }
        int ans = 1 + dfs(r - 1, c - 1);
        return dp[r][c] = ans;
    };

    dfs(10, 10);
}