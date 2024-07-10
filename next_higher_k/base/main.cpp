#include  "../../sum.h"
using namespace std;


// x �Ҳ�ڶ������ڵ��� x ��Ԫ��
namespace NHK_1 {
    vector<int> next_higher_k(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++) {
            pr.emplace_back(-nums[i], i);
        }
        sort(pr.begin(), pr.end());

        set<int> st;
        vector<int> res(n, -1);
        for (auto [v, i] : pr) {
            auto it = st.lower_bound(i);
            if (it != st.end() && next(it) != st.end()) {
                int j = *next(it);
                res[i] = nums[j];
            }
            st.insert(i);
        }
        return res;
    }
}

namespace NHK_2 {
    vector<int> next_higher_k(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++) {
            pr.emplace_back(-nums[i], i);
        }
        sort(nums.begin(), nums.end());

        set<int> st;
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = st.lower_bound(i);
            if (it != st.end() && next(it) != st.end()) {
                int j = *next(it);
                res[i] = nums[j];
            }
            st.insert(i);
        }
        return res;
    }
}

namespace NHK_3 {
    vector<int> next_higher_k(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        set<int> st;
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++) {
            pr.emplace_back(-nums[i], i);
        }
        sort(pr.begin(), pr.end());
        for (int i = 0; i < n; i++) {
            auto it = st.lower_bound(i);
            if (it != st.end() && next(it) != st.end()) {
                res[i] = nums[*next(it)];
            }
            st.insert(i);
        }
        return res;
    }
}

namespace NHK_4 {
    vector<int> next_higher_k(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++) {
            pr.emplace_back(-nums[i], i);
        }
        sort(pr.begin(), pr.end());
        set<int> st;
        for (int i = 0; i < n; i++) {
            auto [d, j] = pr[i];
            auto it = st.lower_bound(j);
            if (it != st.end() && next(it) != st.end()) {
                it = next(it);
                res[j] = *it;
            }
            st.insert(i);
        }
    }
}

namespace NHK_5 {
    vector<int> next_higher_k(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++) {
            pr.emplace_back(-nums[i], i);
        }
        sort(pr.begin(), pr.end());

        set<int> st;
        for (int i = 0; i < n; i++) {
            auto [d, j] = pr[i];
            auto it = st.lower_bound(j);
            if (it != st.end() && next(it) != st.end()) {
                it = next(it);
                res[j] = *it;
            }
            st.insert(j);
        }
    }
}

void test() {
    using NHK_5::next_higher_k;
    vector<int> nums;
    vector<int> res;

    // ans : [9, 6, 6, -1, -1]
    nums = {2, 4, 0, 9, 6};
    res = NHK_1::next_higher_k(nums);
    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;

}
int main() {
    test();
    return 0;
}
