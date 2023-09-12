#include "../../main.h"


static constexpr  int mx = 10000005;
vector<int> divisors[mx];
int init = []() {
    for (int i = 1; i < mx; i++) {
        for (int j = i; j < mx; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();

void test() {
    int ma = 0, mb = -1;
    for (int i = 1; i < mx; i++) {
        if (divisors[i].size() > ma) {
            ma = divisors[i].size();
            mb = i;
        }
    }
    cout << mb << " " << ma << endl;
    for (auto& e : divisors[mb]) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}