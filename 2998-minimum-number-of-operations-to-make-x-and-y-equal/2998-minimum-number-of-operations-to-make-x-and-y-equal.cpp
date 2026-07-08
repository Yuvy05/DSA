class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x < y) return y-x ;
        map<int,int>vis ;
        //bfs
        queue<pair<int,int>>q ; // (num , dist) ;
        q.push({x,0}) ;
        vis[x] = 1 ;
        while(!q.empty()){
            auto pair = q.front() ; q.pop() ;
            if(pair.first == y){
                return pair.second ;
            } 
            if(pair.first % 11 == 0 and !vis[pair.first/11]){
                q.push({pair.first/11 , pair.second+1}) ;
                vis[pair.first/11]++ ;
            }
            if(pair.first % 5 == 0 and !vis[pair.first/5]){
                q.push({pair.first/5 , pair.second+1}) ;
                vis[pair.first/5]++ ;
            }
            if(pair.first - 1 >= 1 and !vis[pair.first-1]){
                q.push({pair.first-1 , pair.second+1}) ;
                vis[pair.first-1]++ ;
            }
            if(pair.first + 1 <= pair.first + 11 and !vis[pair.first+1]){
                q.push({pair.first+1 , pair.second+1}) ;
                vis[pair.first+1]++ ;
            }
        }
        return -1 ;
    }
};