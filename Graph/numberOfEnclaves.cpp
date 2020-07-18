class Solution {
    public:
    void dfs(int i, int j, vector < vector < int > > &grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
    }

    int numEnclaves(vector < vector < int > > &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (auto x : {0, rows - 1}) {
            for (int j = 0; j < cols; j++) {
                dfs(x, j, grid);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (auto x : {0, cols - 1}) {
                dfs(i, x, grid);
            }
        }

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                count+= grid[i][j];
            }
        }
        return count;
    }
};
