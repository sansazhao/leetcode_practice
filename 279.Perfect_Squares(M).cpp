class Solution {
public:
     vector<int> generateSquares(int n){
        vector<int> squares;
        int square = 1;
        int diff = 3;
        while(square<=n){
            squares.push_back(square);
            square += diff;
            diff += 2;  // 1 4 9 16 平方数产生规律
        }
        return squares;
    }
    
    int numSquares(int n) {
        vector<int>squares = generateSquares(n);
        queue<int>q;
        bool marked[n+1];
        for(int i = 0; i < n + 1; ++i)
            marked[i] = false;
        q.push(n);
        marked[n] = true;
        int level = 0;
        while (!q.empty()){
            int size = q.size();
            level++;
            while (size-- > 0){
                int cur = q.front();
                q.pop();
                for (auto s: squares){
                    int next = cur - s;
                    if (next < 0)
                        break;
                    if (next == 0)
                        return level;
                    if (marked[next])
                        continue;
                    marked[next] = true;
                    q.push(next);
                }
            }
        }
        return n;
    }
    
   
};