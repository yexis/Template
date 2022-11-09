#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
