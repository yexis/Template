#include <iostream>
#include <vector>
using namespace std;

// 792 ƥ�������еĵ�����
//
// �����ַ��� s?���ַ�������?words, ����??words[i]?����s�������еĵ��ʸ���?��
//
// �ַ����� ������ �Ǵ�ԭʼ�ַ��������ɵ����ַ��������Դ���ɾȥһЩ�ַ�(������none)�������ı������ַ������˳��
//
// ���磬 ��ace�� �� ��abcde�� �������С�

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
