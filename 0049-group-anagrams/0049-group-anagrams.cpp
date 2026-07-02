class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<string , vector<string>>mp ;
        for(auto j : s){
            vector<int>v(26,0);
            for(char i : j){
                v[i - 'a']++ ;
            }
            string key = to_string(v[0]);
            for(int i = 1 ; i < 26 ; i ++){
                key += ','+v[i] ;
            }
            mp[key].push_back(j) ;
        }
        vector<vector<string>>ans ;
        for(auto i : mp){
            ans.push_back(i.second) ;
        }
        return ans ;
    }
};