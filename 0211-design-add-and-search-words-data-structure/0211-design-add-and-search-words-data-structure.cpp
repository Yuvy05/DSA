class Node{
    public:
    Node* links[26] = {nullptr} ;
    bool flag = false ;

    bool contains_elements(char ch){
        return (links[ch-'a'] != NULL) ;
    }
    void put(char ch , Node* node){
        links[ch-'a'] = node ;
    }
    Node* get(char ch){
        return links[ch-'a'] ;
    }
    void setEnd(){
        flag = true ;
    }
    bool isEnd(){
        return flag ;
    }
};
class WordDictionary {
    Node* root ;
public:
    WordDictionary() {
        root = new Node() ;
    }
    
    void addWord(string word) {
        Node* node = root ;
        for(int i = 0 ; i < word.size() ; i++){
            Node* newnode = new Node() ;
            if(!node -> contains_elements(word[i])){
                node -> put(word[i],newnode) ; // add new node
            }
            node = node -> get(word[i]) ; //move to reference node
        }
        node -> setEnd() ;
    }
    bool dfs(Node *node ,int start , string &word){
        for(int i = start ; i < word.size() ; i++){
            if(word[i] == '.'){
                for(auto temp : node -> links){
                    if(temp != NULL and dfs(temp , i+1 , word)){
                        return true ;
                    }
                }
                return false ;
            }
            else{
                if(node -> contains_elements(word[i])){
                    node = node -> get(word[i]) ;
                }
                else{
                    return false ;
                }
            }
        }
        return node -> isEnd() ;
    }
    bool search(string word) {
        return dfs(root , 0 , word) ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */