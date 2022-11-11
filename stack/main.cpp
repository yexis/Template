#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace STACK_1 {
    // 下一个更大元素 从前往后遍历 单调减
    vector<int> get_next_higher(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    // 下一个更大元素 从后往前遍历 单调减
    vector<int> get_next_higher_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = nums[st.top()];
            }
            st.push(i);
        }
        return res;
    }

    // 下一个更小元素 从前往后遍历 单调增
    vector<int> get_next_lower(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> get_next_lower_2(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = nums[st.top()];
            }
            st.push(i);
        }
        return res;
    }

}

namespace STACK_2 {
    vector<int> get_next_higher(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
}

using STACK_2::get_next_higher;
using STACK_1::get_next_higher_2;
using STACK_1::get_next_lower;
using STACK_1::get_next_lower_2;
// 下一个更大元素
void test() {
    // ans : 8 8 9 6 9 20 20 -1 -1
    vector<int> nums = {3,1,8,5,6,9,0,20,7};
    auto res = get_next_higher(nums);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << "\n";
}

// 下一个更大元素
void test_2() {
    // ans : 8 8 9 6 9 20 20 -1 -1
    vector<int> nums = {3,1,8,5,6,9,0,20,7};
    auto res = get_next_higher_2(nums);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << "\n";
}

// 下一个更小元素
void test_3() {
    // ans : 1 0 5 0 0 0 -1 7 -1
    vector<int> nums = {3,1,8,5,6,9,0,20,7};
    auto res = get_next_lower(nums);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << "\n";
}

// 下一个更小元素
void test_4() {
    // ans : 1 0 5 0 0 0 -1 7 -1
    vector<int> nums = {3,1,8,5,6,9,0,20,7};
    auto res = get_next_lower_2(nums);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << "\n";
}
int main() {
    test();
    test_2();
    test_3();
    test_4();
    return 0;
}
