class Solution {
public:
    void bfs(vector<vector<char>>& grid ,vector<vector<int>>&vis, int row , int col){
        vis[row][col] = 1 ;
        queue<pair<int,int>>q ;
        int dirx[4] = {0,1,0,-1} ;
        int diry[4] = {1,0,-1,0} ;
        q.push({row,col}) ;
        while(q.size()){
            pair<int,int>p = q.front() ;
            q.pop() ;
            for(int i = 0 ; i < 4 ; i++){
                int nr = p.first + dirx[i] , nc = p.second + diry[i];
                if(nr >= 0 and nr < grid.size() and nc >= 0
                and nc < grid[0].size() and vis[nr][nc] == 0 and grid[nr][nc] == '1'){
                    q.push({nr,nc}) ;
                    vis[nr][nc] = 1 ;
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int ct = 0 ;
        int n = grid.size() , m = grid[0].size() ;
        vector<vector<int>>vis(n,  vector<int>(m,0)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' and vis[i][j] == 0){
                    ct ++ ;
                    bfs(grid , vis, i , j ) ;
                }
            }
        }
        return ct ;
    }
};