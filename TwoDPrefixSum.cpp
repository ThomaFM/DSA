//2D Prefix Sum, quite fast, does from bottom left corner to top right.
void pref(vector<vector<int>> &grid){ //CHANGE TO LONG IF NEED!
    for(auto &row: grid) row.push_back(0);
    grid.emplace_back(grid[0].size());
    for(int i = grid.size()-2; i >= 0; i--){
        for(int j = grid[0].size()-2; j>=0; j--){
            grid[i][j]+=(grid[i+1][j]+grid[i][j+1]-grid[i+1][j+1]);
        }
    }
}
//upper left, bottom right, CHANGE TO LONG IF NEED
int query(int up, int le, int bo, int ri,vector<vector<int>> &grid){
    return grid[up][le]-grid[bo+1][le]-grid[up][ri+1]+grid[bo+1][ri+1];
}
