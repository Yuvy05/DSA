class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9),col(9),box(9) ;
        for(int i = 0 ; i < 9 ; i ++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    continue ;
                }
                char v = board[i][j] ;
                int bx = (i/3)*3 + j/3 ;
                if(row[i].count(v) or col[j].count(v) or box[bx].count(v)) 
                    return false ;
                row[i].insert(v) ;
                col[j].insert(v) ;
                box[bx].insert(v) ;
            }
        }
        return true ;
    }
};