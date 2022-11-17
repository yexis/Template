#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
const int inf = 2e9;

// 1425. �����Ƶ�������sum���ֵ
// key:
// 1. �������������Ҫ�����������ʲô
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
    // ֱ��ʹ�õ�������
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

    // ���������Ż�DP
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
    // deque �Ż� dp
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

using DQ_2::cal;
using DQ_3::max_sum;
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
