
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (numMap.count(comp)) {
                return {numMap[comp], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = { 2,7,11,15 };
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    // 输出结果
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}