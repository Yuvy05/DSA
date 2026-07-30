class Solution {
public:
    int rec(int i ,int j , vector<vector<int>>& matrix , vector<vector<int>>&dp ){
        //base case 
        if(dp[i][j] != -1) return dp[i][j] ;
        int x[4] = {0,1,0,-1};
        int y[4]= {-1,0,1,0} ;
        int pathlen = 1 ; 
        for(int idx = 0 ; idx < 4 ; idx++){
            int newx = i +x[idx] ;
            int newy = j +y[idx] ;
            // boundary check
            if(newx >= 0 && newx < matrix.size() &&
               newy >= 0 && newy < matrix[0].size()) {

                // increasing condition
                if(matrix[newx][newy] > matrix[i][j]) {

                    pathlen = max(pathlen , 1+rec(newx,newy,matrix,dp)) ;
                }
            }
        }
        return dp[i][j] = pathlen ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int lpath = 1 ; 
        vector<vector<int>>dp(matrix.size() , vector<int>(matrix[0].size() , -1)) ;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                lpath = max(lpath , rec(i,j,matrix,dp)) ;
            }
        }
        return lpath ;
    }
};