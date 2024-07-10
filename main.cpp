#include <iostream>
#include <queue>
#include <array>
#include <unordered_map>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> partitionLabels(string s) {
    vector<int> last_occurrence(26, 0);

    // 记录每个字符最后出现的位置
    for (int i = 0; i < s.size(); ++i) {
        last_occurrence[s[i] - 'a'] = i;
    }

    vector<string> partitions;
    int start = 0, end = 0;

    for (int i = 0; i < s.size(); ++i) {
        // 更新当前字符的最远出现位置
        end = max(end, last_occurrence[s[i] - 'a']);

        // 如果当前索引等于最远出现位置，找到一个分割点
        if (i == end) {
            partitions.push_back(s.substr(start, end - start + 1));
            start = i + 1;
        }
    }

    return partitions;
}

int main() {
    string s = "adefaddaccc";
    vector<string> result = partitionLabels(s);

    for (const string& partition : result) {
        cout << partition << " ";
    }
    // 输出: ababcbaca defegde hijhklij
    return 0;
}
