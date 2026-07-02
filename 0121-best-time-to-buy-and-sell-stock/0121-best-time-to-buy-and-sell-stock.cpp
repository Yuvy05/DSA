class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mn = p[0] , profit = 0 ;
        for(int i =1 ; i < p.size() ; i++){
            int cost = p[i] - mn ;
            profit = max(cost,profit) ;
            mn = min(mn , p[i]) ;
        }
        return profit ;
    }
};