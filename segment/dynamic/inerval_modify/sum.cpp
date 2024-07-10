//
// Created by yex on 2024/5/31.
//

#include "../../../sum.h"

namespace INTERVAL_MODIFY_SUM_1 {
struct Node {
    int l, r, m;
    int f, z;
    Node* left;
    Node* right;
    Node(int ll, int rr) {
        l = ll;
        r = rr;
        m = (l + r) >> 1;
        f = 0;
        z = 0;
        left = nullptr;
        right = nullptr;
    }
};

struct Segment {
    Node* root;
    Segment() {
        root = new Node(1, 1e9);
    }
    void add(Node* p, int L, int R, int u) {
        if (p == nullptr) {
            p = root;
        }
        if (L > R) {
            return;
        }
        if (L <= p->l && R >= p->r) {
            p->f = (p->r - p->l + 1) * u;
            p->z = u;
            return;
        }
        // push down
        if (p->left == nullptr) {
            p->left = new Node(p->l, p->m);
        }
        if (p->right == nullptr) {
            p->right = new Node(p->m + 1, p->r);
        }
        if (p->z) {
            p->left->f = (p->left->r - p->left->l + 1) * p->z;
            p->right->f = (p->right->r - p->right->l + 1) * p->z;
            p->left->z = p->z;
            p->right->z = p->z;
            p->z = 0;
        }
        if (L <= p->m) {
            add(p->left, L, R, u);
        }
        if (R > p->m) {
            add(p->right, L, R, u);
        }
        p->f = p->left->f + p->right->f;
    }

    int ask(Node* p, int L, int R) {
        if (p == nullptr) {
            p = root;
        }
        if (L > R) {
            return 0;
        }
        if (L <= p->l && R >= p->r) {
            return p->f;
        }
        int ans = 0;
        // push down
        if (p->left == nullptr) {
            p->left = new Node(p->l, p->m);
        }
        if (p->right == nullptr) {
            p->right = new Node(p->m + 1, p->r);
        }
        if (p->z) {
            p->left->f = (p->left->r - p->left->l + 1) * p->z;
            p->right->f = (p->right->r - p->right->l + 1) * p->z;
            p->left->z = p->z;
            p->right->z = p->z;
            p->z = 0;
        }
        if (L <= p->m) {
            ans += ask(p->left, L, R);
        }
        if (R > p->m){
            ans += ask(p->right, L, R);
        }
        return ans;
    }
};
}

