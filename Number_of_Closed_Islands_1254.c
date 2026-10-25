void dfs(int** grid, int r, int c, int rows, int cols) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 0) {
        return;
    }
    
    grid[r][c] = 1;
    
    dfs(grid, r - 1, c, rows, cols);
    dfs(grid, r + 1, c, rows, cols);
    dfs(grid, r, c - 1, rows, cols);
    dfs(grid, r, c + 1, rows, cols);
}

int closedIsland(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    
    int cols = gridColSize[0];
    
    for (int i = 0; i < gridSize; i++) {
        if (grid[i][0] == 0) dfs(grid, i, 0, gridSize, cols);
        if (grid[i][cols - 1] == 0) dfs(grid, i, cols - 1, gridSize, cols);
    }
    
    for (int j = 0; j < cols; j++) {
        if (grid[0][j] == 0) dfs(grid, 0, j, gridSize, cols);
        if (grid[gridSize - 1][j] == 0) dfs(grid, gridSize - 1, j, gridSize, cols);
    }
    
    int closed_islands = 0;
    for (int i = 1; i < gridSize - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            if (grid[i][j] == 0) {
                closed_islands++;
                dfs(grid, i, j, gridSize, cols);
            }
        }
    }
    
    return closed_islands;
}
