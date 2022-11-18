#include <iostream>
#include <vector>
using namespace std;

// 792 匹配子序列的单词数
//
// 给定字符串 s?和字符串数组?words, 返回??words[i]?中是s的子序列的单词个数?。
//
// 字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。
//
// 例如， “ace” 是 “abcde” 的子序列。

int numMatchingSubseq(string s, vector<string> words) {
    int ans = 0;
    int n = s.size();
    vector<vector<int> > v(26);
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        v[idx].emplace_back(i);
    }

    for (auto& w : words ) {
        int last = -1;
        for (int i = 0; i < w.size(); i++) {
            int idx = w[i] - 'a';
            auto it = upper_bound(v[idx].begin(), v[idx].end(), last);
            if (it == v[idx].end()) {
                last = -1;
                break;
            }
            last = *it;
        }
        if (last != -1) {
            ans++;
        }
    }
    return ans;
}
int main() {
    cout << numMatchingSubseq("abcde", {"a", "bb", "acd", "ace"}) << endl;
    cout << numMatchingSubseq("dsahjpjauf", {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"}) << endl;
    return 0;
}
