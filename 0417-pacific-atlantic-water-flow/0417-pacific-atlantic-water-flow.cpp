class Solution {
public:
    int dirx[4] = {0,1,0,-1} ;
    int diry[4] = {1,0,-1,0} ;
    void dfs(int r , int c , vector<vector<int>>& heights ,vector<vector<int>> &vis , int prev){
        if(vis[r][c] == 1) return ;

        vis[r][c] = 1 ;
        for(int i= 0 ; i < 4 ; i++){
            int nr = r + dirx[i] ;
            int nc = c + diry[i] ;
            if(nr >= 0 and nr < heights.size()
                and nc >= 0 and nc < heights[0].size() 
                and heights[nr][nc] >= prev and vis[nr][nc] == 0){
                    dfs(nr,nc,heights,vis,heights[nr][nc]) ;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size() ;
        vector<vector<int>> ans ;
        vector<vector<int>>pacific(n , vector<int>(m)) , atlantic(n , vector<int>(m)) ;
        for(int c = 0 ; c < m ; c++){
            dfs(0,c,heights ,pacific ,heights[0][c] ) ;
            dfs(n-1,c ,heights ,atlantic,heights[n-1][c]) ;
        }
        for(int r = 0 ; r < n ; r++){
            dfs(r,0,heights , pacific , heights[r][0]) ;
            dfs(r , m-1 , heights, atlantic, heights[r][m-1]) ;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(pacific[i][j] and atlantic[i][j]){
                    ans.push_back({i,j}) ;
                }
            }
        }
        return ans ;
    }
};