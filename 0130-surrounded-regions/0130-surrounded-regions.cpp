class Solution {
public:
    int dirx[4] = {0,1,0,-1} ;
    int diry[4] = {1,0,-1,0} ;
    void dfs(int row , int col , vector<vector<char>>& board){
        for(int i = 0 ; i < 4 ; i++){
            int nr = row + dirx[i] ;
            int nc = col + diry[i] ;
            if(
                nr >= 0 and nr < board.size() and
                nc >= 0 and nc < board[0].size() and board[nr][nc] == 'O'
                ){
                    board[nr][nc] = 'T' ;
                    dfs(nr,nc,board) ;
                }
        }
    }
    void solve(vector<vector<char>>& board) {
        // 1 convert boundary 'O' to T
        // 2 convert rest of 'O' to X
        // 3 convert 'T' to 'O'
        int n = board.size() , m = board[0].size() ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O' and 
                (i == 0 or i == n-1 or j== 0 or j == m-1)
                ){
                    board[i][j] = 'T';
                    dfs(i,j,board) ;
                }
            }
        } 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X' ;
                }
            }
        } 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O' ;
                }
            }
        } 

    }
};