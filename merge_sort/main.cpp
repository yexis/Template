#include <iostream>
#include <vector>
using namespace std;

namespace MS {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        int i = l, j = m + 1, k = 0;
        vector<int> tmp(r - l + 1);
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }

        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
   }
    void test() {
        vector<int> nums = {5,2,3,1,6,3,78,19,432};
        merge_sort(nums, 0, nums.size() - 1);
        for (auto e : nums ) {
            cout << e << " ";
        }
        cout << "\n";
    }
}

namespace MS_1 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l , m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }

        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }

    void test() {
        vector<int> nums = {1,5,5423,652,62,62,74,243,73};
        merge_sort(nums, 0, nums.size() - 1);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
}


namespace MS_2 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }

    void test() {
        vector<int> nums = {5,6,2,3,8,9,1,4};
        merge_sort(nums, 0, nums.size() - 1);
        for (auto e : nums) {
            cout << e << " ";
        }
        cout << endl;
    }
}

namespace MS_3 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        int i = l, j = m + 1, k = 0;
        vector<int> tmp(r - l + 1);
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }
    void test() {
        vector<int> nums = {4,2,6,4,2,1,6,7,2};
        merge_sort(nums, 0, nums.size() - 1);
        for (auto e : nums) {
            cout << e << " ";
        }
    }
}

namespace MS_4 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }
}
namespace MS_5 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }

        for (int d = l; d <= r; d++) {
            nums[d] = tmp[d - l];
        }
    }
}

namespace MS_6 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }
}

namespace MS_7 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }
}

namespace MS_8 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }
}

using MS_6::merge_sort;
void test() {
    // ans : 1 2 2 2 4 4 6 6 7
    vector<int> nums = {4,2,6,4,2,1,6,7,2};
    merge_sort(nums, 0, nums.size() - 1);
    for (auto e : nums) {
        cout << e << " ";
    }
}

int main() {
    test();
    return 0;
}
