class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq ; //max heap
        for(auto i : stones){
            pq.push(i) ;
        }
        while(pq.size()>1){
            int f = pq.top() ;
            pq.pop() ;
            int s = pq.top() ;
            pq.pop() ;
            if(abs(f-s) >=1) pq.push(abs(f-s)) ;
        }
        return (pq.size()) ? pq.top() : 0 ;
    }
};