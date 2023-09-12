//
// Created by liguoyang on 2023/9/11.
//

#include "../../main.h"

namespace QP_1 {
    using ll = long long;
    static constexpr int N = 2;
    const int mod = 1e9;
    struct MA {
        vector<vector<int>> v;
        MA() {
            v.assign(N, vector<int>(N));
        }
        void init() {
            for (int i = 0; i < N; i++) {
                v[i][i] = 1;
            }
        }
        MA operator*(const MA& b) {
            MA res;
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

        MA operator^(int b) {
            MA res;
            res.init();

            MA a = *this;
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
    using ll = long long;
    const int mod = 1e9 + 7;
    static constexpr int N = 2;
    struct MA {
        vector<vector<int>> v;
        MA() {
            v.resize(N, vector<int>(N));
        }
        void init() {
            for (int i = 0; i < N; i++) {
                v[i][i] = 1;
            }
        }
        MA operator* (const MA& b) {
            MA res;
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

        MA operator^ (int b) {
            MA res;
            res.init();
            MA a = *this;

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

using namespace QP_1;
void test() {
    MA ma;
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