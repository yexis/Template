#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void print(vector<int> nums) {
    int n = nums.size();
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << "]";
    cout << endl;
}

// 生成长度为n的列表
// 数据范围在[l, r] 且 数据可以重复
void rand_repeat(int n, int l, int r) {
    if (l > r) {
        cout << "error" << endl;
        return;
    }
    vector<int> nums;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int x = rand() % (r - l + 1) + l;
        nums.emplace_back(x);
    }
    print(nums);
    return;
}

// 生成长度为n的列表
// 数据范围在[l, r] 且数据不可重复
// 注 : 必须 r - l + 1 >= n
void rand_not_repeat(int n, int l, int r) {
    vector<int> nums;
    if (n > r - l + 1) {
        cout << "error" << endl;
        return;
    }

    srand(time(0));
    unordered_set<int> st;
    int i = 0;
    while (i < n) {
        int x = rand() % (r - l + 1) + l;
        if (st.count(x)) continue;
        st.insert(x);
        nums.emplace_back(x);
        i++;
    }
    print(nums);
}

void all_num(int n, int x) {
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        nums.emplace_back(x);
    }
    print(nums);
}

void sort_greater(int l, int r) {
    if (l > r) {
        cout << "error" << endl;
        return;
    }
    vector<int> nums;
    for (int d = l; d <= r; d++) {
        nums.emplace_back(d);
    }
    print(nums);
}

void sort_less(int s, int e) {
    vector<int> nums;
    for (int d = s; d >= e; d--) {
        nums.emplace_back(d);
    }
    print(nums);
}

int main() {
    rand_not_repeat(8, 1, 8);
    sort_greater(0, 8);
    sort_less(8, 0);
    all_num(10000, 1);
    return 0;
}
