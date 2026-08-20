class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26) ;
        if(s.size() != t.size()) return false ;
        for(auto i : s){
            freq[i-'a']++ ;
        }
        for(auto i : t){
            if (freq[i-'a'] == 0){
                return false ;
            }
            freq[i-'a']-- ;
        }
        return true ;
    }
};