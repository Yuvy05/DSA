class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n) ;
        vector<int>indegree(n) ;
        // for(int i = 0 ; i < n ; i ++){
        //     prerequistes[i]
        // }
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]) ;
        }
        for(int i = 0 ; i < n ; i++){
            for(auto j : adj[i]){
                indegree[j]++ ;
            }
        }
        queue<int>q ;
        for(int i= 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }
        vector<int>ans;
        while(q.size()){
            int curr = q.front() ;q.pop() ;
            ans.push_back(curr) ; 

            for(auto i : adj[curr]){
                indegree[i] -- ;
                if(indegree[i] == 0)q.push(i) ;
            }
        }
        if(ans.size() == n) return ans ;
        else return {} ;
    }
};