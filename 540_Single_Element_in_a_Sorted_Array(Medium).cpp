//二分查找 判断下标奇偶
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int res;
        while(l<r){
            int m = l+ (r-l)/2;
            if(m % 2 == 1)
                m--;//m为偶数
            if(nums[m] == nums[m+1])
                l = m + 2;
            else
                r = m;
        }
        return nums[l];
    }
};