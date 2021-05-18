//bfs, queue记录点坐标
//在访问点时将路径长度set到点，下次访问时非零则表明已经遍历过。
//数组dx dy表示8个方向

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;
        int n = grid[0].size();
        if (n == 1 && grid[0][0] == 0)
            return 1;

        grid[0][0] = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty())
        {
            pair<int, int> point = q.front();
            int x = point.first;
            int y = point.second;
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0)
                {
                    grid[nx][ny] = grid[x][y] + 1; //若非零，则已经visit并set过
                    // printf("%d %d %d\n", nx, ny, grid[nx][ny]);
                    if (nx == n - 1 && ny == n - 1)
                        return grid[nx][ny];
                    q.push({nx, ny});
                }
            }
            q.pop();
        }
        return -1;
    }
};