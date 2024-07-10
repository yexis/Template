//
// Created by liguoyang on 2023/4/24.
//
#include "../../sum.h"

// Ŀ��
// 1. �������������İ�λ��Ľ�����Լ�ֵ���ڸý����������ĸ�����
// 2. ��λ������������������ֵ����������̳���/����ȡ�

// ������Ҫ�Ľ���
// 1. �������(��˵�)Ϊi�������飬��������������չʱ��nums[j]ֻ��ʹ������������Ԫ�ػ�����ĺ� ���� �� ����
// 2. �������Ϊi�������飬������� ��ȵ������Ҷ˵㹹��һ������������

// �ص�
// 1. [|����] �����䵥���� (���ż���Ԫ�ص����ӣ�����������Ԫ�ص�gcd Ҫô���䣬Ҫô����)
// 2. ���ƵĲ������� [&����]������  [gcd]������
class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int, int>> ors; // ��λ���ֵ + ��Ӧ��������Ҷ˵����Сֵ
        for (int i = n - 1; i >= 0; --i) {
            ors.emplace_back(0, i);
            ors[0].first |= nums[i];
            int k = 0;
            // ע������ors����󳤶ȣ����ᳬ��32
            // Ϊʲô����Ϊorsֻ����ÿ��ֵ����С�±꣬�ظ�Ԫ��ֻ��һ���±꣬��ֻ�е�ֵ�����仯ʱ��ors�вŻ����Ԫ��
            // �����i��ʼ��Ԫ�����仯
            for (int j = 1; j < ors.size(); ++j) {
                ors[j].first |= nums[i];
                if (ors[k].first == ors[j].first)
                    ors[k].second = ors[j].second; // �ϲ���ֵͬ���±�ȡ��С��
                else ors[++k] = ors[j];
            }
            ors.resize(k + 1);
            // ����ֻ�õ��� ors[0]�������Ŀ�ĳ�����������֣������� ors �в���
            ans[i] = ors[0].second - i + 1;
        }
        return ans;
    }

    vector<int> smallestSubarrays2(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        deque<pair<int, int>> ors; // ��λ���ֵ + ��Ӧ��������Ҷ˵����Сֵ
        for (int i = n - 1; i >= 0; --i) {
            ors.emplace_front(0, i);
            ors[0].first |= nums[i];
            int k = 0;
            for (int j = 1; j < ors.size(); ++j) {
                ors[j].first |= nums[i];
                if (ors[k].first == ors[j].first) {

                } else ors[++k] = ors[j];
            }
            ors.resize(k + 1);
            // ����ֻ�õ��� ors[0]�������Ŀ�ĳ�����������֣������� ors �в���
            ans[i] = ors.back().second - i + 1;
        }
        return ans;
    }

    void test() {
        vector<int> nums, res;
        nums = {1,0,2,1,3};
        res = smallestSubarrays(nums);
        for (auto& e : res) cout << e << " "; cout << endl;

        res = smallestSubarrays2(nums);
        for (auto& e : res) cout << e << " "; cout << endl;

    }
};

int main() {
    Solution so;
    so.test();

}