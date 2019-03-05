// 飞镖射中气球 → 按左值排序，从而求最少交集数
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty()) 
            return 0;
        sort(points.begin(), points.end());
        int right = points[0].second;
        int res = 1;
        for(int i = 1; i < points.size(); ++i){
            if(points[i].first > right){ //in
                ++res;
                right = points[i].second;
                continue;
            }
            right = min(right, points[i].second);    //update the intersection 
        }
        return res;
    }
};