//
// Created by liguoyang on 2023/4/24.
//
#include "../../main.h"

// 目标
// 1. 求出所有子数组的按位或的结果，以及值等于该结果的子数组的个数。
// 2. 求按位或结果等于任意给定数字的子数组的最短长度/最长长度。

// 两个重要的结论
// 1. 对于起点(左端点)为i的子数组，当子数组向右扩展时，nums[j]只能使得子数组所有元素或操作的和 增加 或 不变
// 2. 对于起点为i的子数组，或操作和 相等的所有右端点构成一段连续的区间

// 重点
// 1. [|操作] 的区间单调性 (随着集合元素的增加，集合中所有元素的gcd 要么不变，要么增加)
// 2. 类似的操作还有 [&操作]单调降  [gcd]单调降
class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> ors; // 按位或的值 + 对应子数组的右端点的最小值
        for (int i = n - 1; i >= 0; --i) {
            ors.emplace_back(0, i);
            ors[0].first |= nums[i];
            int k = 0;
            // 注意这里ors的最大长度，不会超过32
            // 为什么？因为ors只存了每个值的最小下标，重复元素只存一个下标，且只有当值发生变化时，ors中才会加入元素
            // 从起点i开始，元素最多变化
            for (int j = 1; j < ors.size(); ++j) {
                ors[j].first |= nums[i];
                if (ors[k].first == ors[j].first)
                    ors[k].second = ors[j].second; // 合并相同值，下标取最小的
                else ors[++k] = ors[j];
            }
            ors.resize(k + 1);
            // 本题只用到了 ors[0]，如果题目改成任意给定数字，可以在 ors 中查找
            ans[i] = ors[0].second - i + 1;
        }
        return ans;
    }

    vector<int> smallestSubarrays2(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        deque<pair<int, int>> ors; // 按位或的值 + 对应子数组的右端点的最小值
        for (int i = n - 1; i >= 0; --i) {
            ors.emplace_front(0, i);
            ors[0].first |= nums[i];
            int k = 0;
            for (int j = 1; j < ors.size(); ++j) {
                ors[j].first |= nums[i];
                if (ors[k].first == ors[j].first) {

                } else ors[++k] = ors[j];
            }
            ors.resize(k + 1);
            // 本题只用到了 ors[0]，如果题目改成任意给定数字，可以在 ors 中查找
            ans[i] = ors.back().second - i + 1;
        }
        return ans;
    }

    void test() {
        vector<int> nums, res;
        nums = {1,0,2,1,3};
        res = smallestSubarrays(nums);
        for (auto& e : res) cout << e << " "; cout << endl;

        res = smallestSubarrays2(nums);
        for (auto& e : res) cout << e << " "; cout << endl;

    }
};

int main() {
    Solution so;
    so.test();

}