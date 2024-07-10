//
// Created by yex on 2024/6/7.
//

#include "../sum.h"
namespace SCANLINE_1 {
    struct line {
        int x;
        int y1, y2;
        int tag;
    };

    struct Node {
        int l, r;
        int len, cnt;
    };

    vector<Node> tr;
    vector<int> val;
    vector<line> lines;
    void init(int mm) {
        tr = vector<Node>(mm);
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, 0};
        if (l == r) {
            return;
        }
        int m = (l + r) >> 1;
        build(u * 2, l, m);
        build(u * 2 + 1, m + 1, r);
    }
    void push_up(int u) {
        int l = tr[u].l, r = tr[u].r;
        if (tr[u].cnt) {
            tr[u].len = val[r + 1 - 1] - val[l - 1];
        } else {
            tr[u].len = tr[u * 2].len + tr[u * 2 + 1].len;
        }
    }
    void add(int u, int L, int R, int tag) {
        if (L > tr[u].r || R < tr[u].l) {
            return;
        }
        if (L <= tr[u].l && R >= tr[u].r) {
            tr[u].cnt += tag;
            push_up(u);
            return;
        }
        add(u * 2, L, R, tag);
        add(u * 2 + 1, L, R, tag);
        push_up(u);
    }
}

using namespace SCANLINE_1;
class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;
    int rectangleArea(vector<vector<int>>& rec) {
        int n = rec.size();
        val.resize(0);
        lines.resize(0);
        for (auto& r : rec) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            lines.emplace_back(line{x1, y1, y2, 1});
            lines.emplace_back(line{x2, y1, y2, -1});
            val.emplace_back(y1);
            val.emplace_back(y2);
        }
        sort(lines.begin(), lines.end(), [&](const auto& a, const auto& b) {
            if (a.x != b.x) return a.x < b.x;
            return a.tag > b.tag;
        });

        // 离散化
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        auto get = [&](int x) {
            return lower_bound(val.begin(), val.end(), x) - val.begin();
        };
        int m = val.size();
        init(4 * m + 5);

        build(1, 1, m - 1);
        ll ans = 0;
        for (int i = 0, pre = 0; i < lines.size(); i++) {
            auto li = lines[i];
            int y1 = get(li.y1);
            int y2 = get(li.y2);
            ll tmp = 1ll * (li.x - pre) * tr[1].len;
            ans += tmp;
            ans %= mod;
            add(1, y1 + 1, y2 + 1 - 1, li.tag);
            pre = li.x;
        }
        return ans;
    }

    void test() {
        int ans = 0;
        vector<vector<int>> rec;

        // 6
        rec = {{0,0,2,2}, {1,0,2,3}, {1,0,3,1}};
        ans = rectangleArea(rec);
        cout << ans << endl;

        // 49
        rec = {{0,0,1000000000,1000000000}};
        ans = rectangleArea(rec);
        cout << ans << endl;
    }
};

int main() {
    Solution so;
    so.test();
    return 0;
}
