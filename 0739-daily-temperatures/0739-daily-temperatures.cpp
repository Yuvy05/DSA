class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st ;
        vector<int> ans(temp.size(),0) ;
        st.push({temp[0],0}) ;
        for(int i= 1; i < temp.size() ; i++){
            while(!st.empty() and st.top().first < temp[i]){
                auto pair = st.top() ;
                st.pop() ;
                ans[pair.second] = i - pair.second ;
            }
            st.push({temp[i],i}) ;
        }
        return ans ;
    }
};