class Solution {
    public:
    int orangesRotting(vector < vector < int > > &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue < pair <int, int > > q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        q.push({-1, -1});

        int time = 0;
        int i, j;
        while (q.empty() != true) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if (i == -1 && j == -1) {
                if (q.size() == 0) {
                    break;
                }
                time++;
                q.push({-1, -1});
                continue;
            }

            if (i + 1 < rows && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
            }

            if (j + 1 < cols && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
            }

            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
            }

            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return time;


    }
};
