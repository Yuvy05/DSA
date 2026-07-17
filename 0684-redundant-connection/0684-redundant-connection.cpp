class Solution {
public:
    int find(int u ,vector<int>&parent){
        if(u == parent[u]) return u ;
        
        return parent[u] = find(parent[u],parent) ;
        
    }
    bool Union(int u ,int v , vector<int>&parent,vector<int>&rank){
        int p1 = find(u,parent) ;
        int p2 = find(v,parent) ;
        if(p1== p2) return true ;
        else if(rank[p1]>rank[p2]){
            parent[p2] = p1 ;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1] = p2 ;
        }
        else{
            parent[p1] = p2 ;
            rank[p2]++ ;
        }
        return false ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;
        vector<int>parent(n+1) , rank(n+1,1) ;
        for(int i = 1 ; i<= n ;i++){
            parent[i] = i ;
        }
        for(auto i : edges){
            if(Union(i[0],i[1],parent,rank)){
                return{i[0],i[1]} ;
            }
        }
        return{} ;
    }
    
};