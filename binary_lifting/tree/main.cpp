#include "../../main.h"

// 树上倍增
// 1. 快速计算树上第k个祖先
// 通过fa的形式给出，fa[i]表示每个节点的父节点

namespace BL_1 {
    int n;
    constexpr static int Log = 16;
    // f[i][j]表示从节点i开始往上走2^j个节点后的位置
    vector<vector<int>> f;
    void init(int nn, vector<int>& fa) {
        n = nn;
        fa.resize(n);
        f = vector<vector<int>>(n, vector<int>(Log, -1));
        // f[i][0]就是i的父节点fa[i]
        for (int i = 0; i < n; i++) {
            f[i][0] = fa[i];
        }
        // 从1到Log遍历
        for (int j = 1; j < Log; j++) {
            // 遍历每个节点
            for (int i = 0; i < n; i++) {
                if (f[i][j - 1] != -1) {
                    f[i][j] = f[f[i][j - 1]][j - 1];
                }
            }
        }
    }
}

//-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//1 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//1 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//2 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
//3 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
using namespace BL_1;
void test() {
    int n = 8;
    vector<int> fa = {-1,0,1,1,0,0,2,3};
    init(n, fa);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Log; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    test();
}