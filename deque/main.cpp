#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
