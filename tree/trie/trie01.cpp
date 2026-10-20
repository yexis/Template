//
// Created by yex on 2023/11/25.
//


#include "../sum.h"
namespace TRIE01_1 {
    struct Node {
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child.resize(2);
        }
    };
    struct Trie {
        int b;
        Node* root;
        Trie(int bb) {
            b = bb;
            root = new Node();
        }
        void add(int x) {
            auto p = root;
            for (int i = b; i >= 0; i--) {
                int bit = x >> i & 1;
                if (p->child[bit] == nullptr) {
                    p->child[bit] = new Node();
                }
                p = p->child[bit];
                p->val++;
            }
        }
        void del(int x) {
            auto p = root;
            for (int i = b; i >= 0; i--) {
                int bit = x >> i & 1;
                p = p->child[bit];
                p->val--;
            }
        }
        int ask(int x) {
            int ans = 0;
            auto p = root;
            for (int i = b; i >= 0; i--) {
                int bit = x >> i & 1;
                int xr = bit ^ 1;
                if (p->child[xr] && p->child[xr]->val > 0) {
                    ans |= 1 << i;
                    bit ^= 1;
                }
                p = p->child[bit];
            }
            return ans;
        }
    };
}

using namespace TRIE01_1;
class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int mx = a.back();

        int b = 31 - __builtin_clz(mx);

        int ans = 0;
        int l = 0;
        Trie tr(b);
        for (auto e : a) {
            tr.add(e);
            while (a[l] * 2 < e) {
                tr.del(a[l]);
                l++;
            }
            ans = max(ans, tr.ask(e));
        }
        return ans;
    }
    void test() {
        vector<int> a;
        // 7
        a = {1, 2, 3, 4, 5};
        cout << maximumStrongPairXor(a) << endl;

        // 0
        a = {10, 100};
        cout << maximumStrongPairXor(a) << endl;

        // 1020
        a = {500, 520, 2500, 3000};
        cout << maximumStrongPairXor(a) << endl;
    }
};

int main() {
    Solution so;
    so.test();
}
