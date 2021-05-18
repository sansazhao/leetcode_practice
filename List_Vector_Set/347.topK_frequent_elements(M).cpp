struct record{
    int num;
    int freq;
};

bool compare(const record& r1, const record& r2) {
    return r1.freq > r2.freq;
} 

// 桶排序？ 自定义排序？优化？
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<record>vec;
        vector<int>res;
        sort(nums.begin(),nums.end());
        int tmp = nums[0];
        int f = 0;
        for(int i = 1;i < nums.size(); ++i){
            if(nums[i] == tmp){
                f++;
            }
            else{
                record r;
                r.num = tmp;
                r.freq = f;
                vec.push_back(r);
                f = 0;
                tmp = nums[i];
            }
        }
        record r;
        r.num = tmp;
        r.freq = f;
        vec.push_back(r);
        sort(vec.begin(), vec.end(), compare);
        for(int i = 0; i < k; ++i){
            res.push_back(vec[i].num);
        }
        return res;
    }
};

