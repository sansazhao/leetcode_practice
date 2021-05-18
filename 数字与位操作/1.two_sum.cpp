#include <stdio.h>
using namespace std;

// 哈希表计数
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (hash_map.count(target - nums[i]))
            {
                return {hash_map[target - nums[i]], i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    printf("123\n");
    return 0;
}