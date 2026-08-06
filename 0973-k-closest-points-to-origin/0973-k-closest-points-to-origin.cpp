class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int,vector<int>> ,
            vector<pair<int,vector<int>>> ,
            greater<pair<int,vector<int>>> > pq;
        for(auto i : points){
            int x = i[0] ;
            int y = i[1] ;
            int dist = (x*x + y*y) ;
            pq.push( {dist , {x,y}} ) ;
        }
        vector<vector<int>> res ;
        for(int i =0 ; i < k ; i++){
            pair<int,vector<int>> ans = pq.top() ;
            res.push_back(ans.second) ;
            pq.pop() ;
        }
        return res ;
    }
};