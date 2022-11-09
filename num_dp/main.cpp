#include <iostream>
#include <string>
using namespace std;

namespace NUMDP_1 {
    int f[1000][1000];
    int m;
    string s;
    void init(int num) {
        s = to_string(num);
        m = s.size();
    }
    int dfs(int i, int mask, int is_limit, int is_num) {
        if (i == m) {
            return is_num;
        }
        if (f[i][mask] >= 0) {
            return f[i][mask];
        }
        int res = 0;
        if (!is_num) {
            res = dfs(i + 1, mask, false, false);
        }
        int up = is_limit ? s[i] - '0' : 9;
        for (int j = is_num ? 0 : 1; j <= up; j++) {
            // judge
            res += dfs(i + 1, mask, is_limit && j == up, true);
        }
        return f[i][mask] = res;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
