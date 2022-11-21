#include <iostream>
#include <vector>
using namespace std;

int sumSubseqWidths(vector<int>& nums) {
    int n = nums.size();
    int mx = *max_element(nums.begin(), nums.end());
    vector<int> f(mx + 1), g(mx + 1);
    for (auto e : nums) {
        f[e]++;
    }

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
