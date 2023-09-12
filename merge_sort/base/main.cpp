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

namespace MS_9 {
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

namespace MS_10 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = l + r >> 1;
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

namespace MS_11 {
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

namespace MS_12 {
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
                tmp[k++] = nums[j]++;
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

namespace MS_13 {
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

namespace MS_14 {
    void merge_sort(vector<int>& nums, int l, int r ) {
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

namespace MS_15 {
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

namespace MS_16 {
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
        for (int i = l; i <= r; i++) {
            nums[i] = tmp[i - l];
        }
    }
}

namespace MS_17 {
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

namespace MS_18 {
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
};

namespace MS_19 {
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

namespace MS_20 {
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

namespace MS_21 {
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

namespace MS_22{
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l == r) {
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

namespace MS_23 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l == r) {
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

namespace MS_24 {
    //
    void get_sum_1(vector<int>& nums, vector<int>& sum) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int tol = 0;
            for (int d = 0; d < n; d++) {
                if (mask >> d & 1) {
                    tol += nums[d];
                }
            }
            sum.push_back(tol);
        }
        sort(begin(sum), end(sum));
    }

    void get_sum_2(vector<int>& nums, vector<int>& sum) {
        sum.push_back(0);
        for (int x : nums) {
            vector<int> tmp;
            int n = sum.size();
            int i = 0, j = 0;
            while (i < n && j < n) {
                if (sum[i] <= sum[j] + x) {
                    tmp.emplace_back(sum[i++]);
                } else {
                    tmp.emplace_back(sum[j++] + x);
                }
            }
            while (i < n) {
                tmp.emplace_back(sum[i++]);
            }
            while (j < n) {
                tmp.emplace_back(sum[j++] + x);
            }
            swap(sum, tmp);
        }
    }

    void get_sum_3(vector<int>& nums, vector<int>& sum) {
        sum.push_back(0);
        for (int x : nums) {
            vector<int> tmp;
            int n = sum.size();
            int i = 0, j = 0;
            while (i < n or j < n) {
                if (i == n) {
                    tmp.emplace_back(sum[j++] + x);
                } else if (j == n) {
                    tmp.emplace_back(sum[i++]);
                } else if (sum[i] <= sum[j] + x) {
                    tmp.emplace_back(sum[i++]);
                } else {
                    tmp.emplace_back(sum[j++] + x);
                }
            }
            swap(sum, tmp);
        }
    }

    void test() {
        vector<int> nums = {1, 2, 3, 4};
        vector<int> sum_1;
        get_sum_1(nums, sum_1);
        for (auto& e : sum_1) {
            cout << e << " ";
        }
        cout << endl;

        vector<int> sum_2;
        get_sum_2(nums, sum_2);
        for (auto& e : sum_2) {
            cout << e << " ";
        }
        cout << endl;

        vector<int> sum_3;
        get_sum_3(nums, sum_3);
        for (auto& e : sum_3) {
            cout << e << " ";
        }
        cout << endl;
    }
}

namespace MS_25 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l == r) {
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

namespace MS_26 {
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

namespace MS_27 {
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
}

namespace MS_28 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r ) >> 1;
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

namespace MS_29 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l == r) {
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
}

namespace MS_30 {
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

namespace MS_31 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);
        int i, j, k;
        i = l, j = m + 1, k = 0;
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
}

namespace MS_32 {
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
}

namespace MS_33 {
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + r) >> 1;
        merge_sort(nums, l, m);
        merge_sort(nums, m + 1, r);

        vector<int> tmp(r - l + 1);
        int i, j, k;
        i = l, j = m + 1, k = 0;
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

using MS_33::merge_sort;
void test() {
    // ans : 1 2 2 2 4 4 6 6 7
    vector<int> nums = {4,2,6,4,2,1,6,7,2};
    merge_sort(nums, 0, nums.size() - 1);
    for (auto e : nums) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}
