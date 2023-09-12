#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
const int inf = 2e9;

// 1425. 带限制的子序列sum最大值
// key:
// 1. 抽离出队列中需要保存的内容是什么
namespace DQ_1 {
    int cal(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            int x = nums[i];
            if (!q.empty()) {
                x = x + max(0, q.front().first);
            }
            ans = max(ans, x);
            while (!q.empty() && q.front().first <= x) {
                q.pop_back();
            }
            q.push_back({x, i});
        }
        return ans;
    }
}


namespace DQ_2 {
    // 直接使用单调队列
    int cal(vector<int>& nums, int k) {
        int ans = -inf;
        int n = nums.size();
        deque<pair<int, int> > q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }

            int x = nums[i];
            if (!q.empty()) {
                x = max(x, x + q.front().first);
            }
            ans = max(ans, x);

            while (!q.empty() && q.back().first <= x) {
                q.pop_back();
            }
            q.emplace_back(x, i);
        }
        return ans;
    }

    // 单调队列优化DP
    int max_sum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -inf);
        deque<int> q;
        int ans = -inf;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            int x = nums[i];
            if (!q.empty()) {
                x = max(x, x + dp[q.front()]);
            }
            dp[i] = x;
            ans = max(ans, x);

            while (!q.empty() && dp[q.back()] <= x) {
                q.pop_back();
            }
            q.emplace_back(i);
        }
        return ans;
    }
}

namespace DQ_3 {
    // queue 优化 dp
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> f(n, -inf);
        deque<int> q;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            f[i] = x;
            if (!q.empty()) {
                f[i] = max(f[i], x + f[q.front()]);
            }
            ans = max(ans, f[i]);
            while (!q.empty() && f[q.back()] <= f[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }
        return ans;
    }
}

namespace DQ_4 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        // <val, idx>
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            // 先出
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                x = max(x, x + q.front().first);
            }
            ans = max(ans, x);
            while (!q.empty() && q.back().first <= x) {
                q.pop_back();
            }
            q.push_back({x, i});
        }
        return ans;
    }
}

namespace DQ_5 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                x = max(x, x + q.front().first);
            }
            while (!q.empty() && x >= q.back().first) {
                q.pop_back();
            }
            q.emplace_back(x, i);
        }
    }
}

namespace DQ_6 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                x = max(x, x + q.front().first);
            }
            while (!q.empty() && x >= q.back().first) {
                q.pop_back();
            }
            ans = max(ans, x);
            q.emplace_back(x, i);
        }
        return ans;
    }
}

namespace DQ_7 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            if (!q.empty()) {
                x = max(x, x + q.front().first);
            }
            while (!q.empty() && q.back().first <= x) {
                q.pop_back();
            }
            ans = max(ans, x);
            q.emplace_back(x, i);
        }
        return ans;
    }
}

namespace DQ_8 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> f(n, INT_MAX / 2);
        deque<int> q;

        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front() > k) {
                q.pop_front();
            }
            int x = nums[i];
            if (!q.empty()) {
                x = max(nums[i], nums[i] + f[q.front()]);
            }
            while (!q.empty() && f[q.back()] <= x) {
                q.pop_back();
            }
            f[i] = x;
            ans = max(ans, f[i]);
            q.emplace_back(i);
        }
        return ans;
    }
}

namespace DQ_9 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            int x = nums[i];
            if (!q.empty()) {
                x = max(x, q.front().first + x);
            }
            while (!q.empty() && q.back().first <= x) {
                q.pop_back();
            }
            ans = max(ans, x);
            q.emplace_back(x, i);
        }
        return ans;
    }
}

namespace DQ_10 {
    int max_sum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            while (not q.empty() && i - q.front().second > k) {
                q.pop_front();
            }
            int x = nums[i];
            if (not q.empty()) {
                x = max(x, q.front().first + x);
            }
            while (!q.empty() && q.back().first <= x) {
                q.pop_back();
            }
            ans = max(ans, x);
            q.emplace_back(x, i);
        }
        return ans;
    }

}

using DQ_2::cal;
using DQ_10::max_sum;
void test() {
    // ans : 37
    vector<int> nums = {10, 2, -10, 5, 20};
    int k = 2;
    cout << "ans_1 : " << max_sum(nums, k) << endl;

    // ans : -1
    nums = {-1, -2, -3};
    k = 1;
    cout << "ans_2 : " << max_sum(nums, k) << endl;

    // ans :23
    nums = {10, -2, -10, -5, 20};
    k = 2;
    cout << "ans_3 : " << max_sum(nums, k) << endl;
}

int main() {
    test();
    return 0;
}
