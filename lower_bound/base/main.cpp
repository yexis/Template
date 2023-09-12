#include <iostream>
#include <vector>
using namespace std;
namespace LB {
    void test_compare() {
        vector<pair<int, int>> nums = {{4,4},{3,3},{2,2},{1,1}};
        // auto it = lower_bound(nums.begin(), nums.end(), make_pair(2,3));
        auto it = lower_bound(nums.begin(), nums.end(), make_pair(100,50), [&](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        if (it != nums.end()) {
            cout << it->first << " " << it->second << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
int main() {
    LB::test_compare();
    return 0;
}
