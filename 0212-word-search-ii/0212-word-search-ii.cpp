class Node{
    public:
    Node* link[26] = {nullptr} ;
    bool flag = false ;
    Node* get(char ch){
        return link[ch-'a'] ;
    }
    bool isContains(char ch){
        return (link[ch-'a'] != NULL) ;
    }
    void add(char ch , Node* node){
        link[ch-'a'] = node ;
    }
    bool isEnd(){
        return flag ;
    }
    void setEnd(){
        flag = true ;
    }
    void addWord(string words , Node* root){
        for(int i = 0 ; i < words.size();i++){
            if(!root -> isContains(words[i])){ // if char mnot there 
                Node* newnode = new Node() ; 
                root -> add(words[i],newnode ); // add to the reference trie
            }
            root = root -> get(words[i]) ; // move to the reference trie
        }
        root -> setEnd() ;
    }
};

class Solution {
    Node* root ; 
public:
    void dfs(int r , int c ,vector<vector<char>>& board,  string s , set<string>&res , Node* node , vector<vector<int>>&vis){
        // base case 
        if(r<0 or c<0 or r>=board.size() or c>=board[0].size() or !node -> isContains(board[r][c]) or vis[r][c] == 1){
            return ;
        }

        s += board[r][c] ;
        node = node -> get(board[r][c]) ;
        //chek if the word exists by reaching the last node
        if(node -> isEnd()){
            res.insert(s) ;
        }
        int dirx[4] = {0,0,-1,1} ;
        int diry[4] = {1,-1,0,0} ;

        vis[r][c] = 1 ;
        
        for(int i = 0 ; i < 4 ; i++){
            int newx = r + dirx[i] ;
            int newy = c + diry[i] ;
            dfs(newx,newy,board,s,res,node,vis) ;
        }
        vis[r][c] = 0 ;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        root = new Node() ;
        //Node* head = root ;
        // trie
        for(auto i : words){
            root -> addWord(i,root) ;
        }
        set<string>res ;
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0)) ;
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j< board[0].size() ; j++){
                dfs(i,j,board,"",res,root ,vis) ;
            }
        }
        return vector<string>(res.begin(),res.end());
    }
};