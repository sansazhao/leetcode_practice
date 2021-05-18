// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int i = 0;
        int j = numbers.size() - 1;
        int sum;
        while (i < j){
            sum = numbers[i] + numbers[j];
            if (sum > target)j--;
            else if (sum < target)i++;
            else{
                res.push_back(++i);
                res.push_back(++j);
                return res;
            }
        }
        return res;
    }
};