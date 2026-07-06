class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v ;
        for(int i= 0 ; i < position.size() ; i++){
            v.push_back({position[i],speed[i]}) ;
        }
        sort(v.rbegin(),v.rend()) ;
        stack<double>st ;
        double t = (double)(target - v[0].first)/v[0].second ;
        st.push(t) ;
        for(int i = 1 ; i < v.size() ; i++) {
            t = (double)(target - v[i].first)/v[i].second ;
            if(!st.empty() and st.top() >= t){
                continue ;
            }
            else{
                st.push(t) ;
            }
        }
        return st.size() ;
    }
};