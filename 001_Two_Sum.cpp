// 哈希表计数
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>hash_map;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(hash_map.count(target - nums[i])){
                res.push_back(hash_map[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            hash_map[nums[i]] = i;
        }
        return res;
    }
};