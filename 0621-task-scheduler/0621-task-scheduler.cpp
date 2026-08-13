class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0) ;
        for(auto i : tasks){
            v[i-'A']++ ;
        }
        queue<pair<int,int>> q ; // {count , time when it comes next}
        priority_queue<int> pq ; // max heap
        for(int i = 0 ; i < 26 ; i++){
            if(v[i] > 0)pq.push(v[i]) ;
        }
        int time = 0 ;
        while(pq.size() or q.size()){
            if(pq.empty() and q.size()){
                time = q.front().second ;
            }
            if(q.front().second == time){
                pq.push(q.front().first) ;
                q.pop() ;
            }
            int ct ;
            if(pq.size()){
                ct = pq.top() ;
                pq.pop() ;
            }
            if(ct-1 >0)
                q.push({ct-1,time+n+1}) ;


            time++ ;
        }
        return time ;
    }
};