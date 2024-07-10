//
// Created by liguoyang on 2023/9/11.
//

#include "../../sum.h"

using ll = long long;
const int mod = 1e9 + 7;
static constexpr int N = 2;

namespace QP_1 {
    struct Ma {
        vector<vector<int>> v;
        Ma() {
            v.assign(N, vector<int>(N));
        }
        void init() {
            for (int i = 0; i < N; i++) {
                v[i][i] = 1;
            }
        }
        Ma operator*(const Ma& b) {
            Ma res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        res.v[i][j] += v[i][k] * b.v[k][j];
                        res.v[i][j] %= mod;
                    }
                }
            }
            return res;
        }

        Ma operator^(int b) {
            Ma res;
            res.init();

            Ma a = *this;
            while (b) {
                if (b & 1) {
                    res = res * a;
                }
                a = a * a;
                b >>= 1;
            }
            return res;
        }
    };
}

namespace QP_2 {
    struct Ma {
        vector<vector<int>> v;
        Ma() {
            v.resize(N, vector<int>(N));
        }
        void init() {
            for (int i = 0; i < N; i++) {
                v[i][i] = 1;
            }
        }
        Ma operator* (const Ma& b) {
            Ma res;
            for (int i = 0 ; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        res.v[i][j] += v[i][j] * b.v[k][j];
                        res.v[i][j] %= mod;
                    }
                }
            }
            return res;
        }

        Ma operator^ (int b) {
            Ma res;
            res.init();
            Ma a = *this;

            while (b) {
                if (b & 1) {
                    res = res * a;
                }
                a = a * a;
                b >>= 1;
            }
            return res;
        }
    };
}

namespace QP_3 {
    struct Ma {
        vector<vector<int>> v;
        Ma() {
            v.resize(N, vector<int>(N));
        }
        void init() {
            for (int i = 0; i < N; i++) {
                v[i][i] = 1;
            }
        }
        Ma operator* (const Ma& b) {
            Ma res;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        res.v[i][j] += v[i][k] * b.v[k][j];
                        res.v[i][j] %= mod;
                    }
                }
            }
            return res;
        }
        Ma operator^ (ll b) {
            Ma res;
            res.init();
            Ma a = *this;

            while (b) {
                if (b & 1) {
                    res = res * a;
                }
                a = a * a;
                b >>= 1;
            }
            return res;
        }
    };
}

using namespace QP_3;
void test() {
    Ma ma;
    ma.v = {{1,1},{1,1}};

    ma = ma^4;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ma.v[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    test();
}