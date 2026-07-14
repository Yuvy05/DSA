class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size() , m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m,0)) ;
        queue<pair<int,int>>q ;

        for(int i = 0 ; i < n ; i++ ){
            for(int j =0; j< m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j}) ;
                    vis[i][j] = 1 ;
                }
            }
        }
        int ct = -1 ;
        int dx[4] ={0,1,0,-1} ;
        int dy[4] ={1,0,-1,0} ;
        while(q.size()){
            int sz = q.size() ;
            ct++ ;
            for(int i = 0 ; i < sz ; i++){
                pair<int,int> p =q.front() ;
                q.pop() ;
                for(int j= 0 ; j < 4 ; j++){
                    int nr = p.first + dx[j] ;
                    int nc = p.second + dy[j] ;
                    if(
                        nr >= 0 and nr < grid.size() and
                        nc >= 0 and nc < grid[0].size() and
                        vis[nr][nc] == 0 and grid[nr][nc] == 1
                    ){
                        vis[nr][nc] = 1 ;
                        grid[nr][nc] = 2 ;
                        q.push({nr,nc}) ;
                    }
                }
            }
        }
        for(int i = 0 ; i < n ; i++ ){
            for(int j =0; j< m ; j++){
                if(grid[i][j] == 1){
                    return -1 ;
                }
            }
        }
        return (ct==-1)?0:ct;
        
    }
};