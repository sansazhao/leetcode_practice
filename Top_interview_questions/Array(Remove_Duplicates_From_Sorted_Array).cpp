/*
* Given a sorted array nums, remove the duplicates in-place such that
* each element appear only once and return the new length.
* Do not allocate extra space for another array, you must do this by
* modifying the input array in-place with O(1) extra memory.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = 0;
        int res = 0;
        int j = 0;  //维护一个变量记录不重复的个数，同时修改原数组
        if(nums.size() == 0)
            return 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i])
                nums[j++] = nums[i-1];
        }
        nums[j++] = nums[nums.size()-1];
        return j;
    }
};

int main(){
    Solution s1;
    vector<int> vec = {0,1,1,1,1,2,2,2,2,3,4,5,6};
    int ans = s1.removeDuplicates(vec);
    // for(auto i : vec){
        // cout<< i<<" ";
    // }
    cout << ans;
    return 0;
}
