class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>st (wordList.begin() ,wordList.end()) ;
        queue<pair<string , int>> q ;
        q.push({beginWord , 1}) ;
        st.erase(beginWord) ;
        while(q.size()){
            string word = q.front().first ;
            int step = q.front().second ;
            q.pop() ;
            if(word == endWord) return step ;
            for(int i =0 ; i< word.size() ; i++){
                char original = word[i] ;
                for(char ch = 'a' ; ch<= 'z' ; ch++){
                    word[i] = ch ;
                    if(st.find(word) != st.end()){
                        st.erase(word) ;
                        q.push({word,step+1}) ;
                    }
                }
                word[i] = original ;
            }
        }
        return 0 ;
    }
};