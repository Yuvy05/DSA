class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>&vis , vector<vector<int>>&grid , int &ct ,int &mx){
        mx = max(mx ,ct) ;
        vis[row][col] = 1 ;
        int dirx[4] = {0,1,0,-1} ;
        int diry[4] = {1,0,-1,0} ;
        for(int i = 0 ; i < 4 ; i++){
            int nr = row + dirx[i] ;
            int nc = col + diry[i] ;
            if(nr >= 0 and nr < grid.size() and nc >=0 and 
                nc < grid[0].size() and vis[nr][nc] == 0 and 
                grid[nr][nc] == 1){
                    ct++ ;
                    mx = max(mx,ct) ;
                    dfs(nr , nc , vis , grid,ct,mx) ;
                }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size() , vector<int>(grid[0].size() , 0));
        int mx = 0 ;
        
        for(int i = 0 ; i <grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 and vis[i][j] == 0){
                    int ct = 1 ;
                    dfs(i,j, vis , grid ,ct ,mx) ;
                }
            }
        }
        return mx ;
    }
};