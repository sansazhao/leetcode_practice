class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>>res(r, vector<int>(c, 0));
        int m = nums.size();
        int n = nums[0].size();
        if (r*c != m*n)return nums;
        for (int t = 0; t < m*n; ++t)
            res[t/c][t%c] = nums[t/n][t%n];
        return res;
    }
};