class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        int mx = INT_MIN ;
        stack<pair<int,int>>st ; // height , index
        for(int i = 0 ; i<n ; i++){
            int start = i ;
            while(!st.empty() and st.top().first > heights[i]){
                mx = max(mx , st.top().first*(i-st.top().second)) ;
                start = st.top().second ;
                st.pop() ;
            }
            st.push({heights[i],start}) ;
        }
        while(!st.empty()){
            mx = max(mx , st.top().first*(n-st.top().second));
            st.pop();
        }
        return mx;
    }
};