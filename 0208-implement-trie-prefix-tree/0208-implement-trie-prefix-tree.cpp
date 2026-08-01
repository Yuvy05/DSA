class Node{
    public:
    Node* links[26] = {nullptr} ; // it is array of null pointers
    bool flag = false ;
    bool contains_element(char ch){ 
        // accessing array(links) by indexing 
        // array(links here) contains pointers
        return (links[ch-'a'] != NULL) ;
    }
    void put(char ch , Node* newnode){
        links[ch-'a'] = newnode ;
    }
    Node *get(char ch){
        return links[ch-'a'] ;
    }
    void setEnd(){
        flag = true ;
    }
    bool isEnd(){
        return flag ;
    }
};
class Trie {
    Node* root ;
public:
    Trie() {
        root = new Node() ;
    }
    
    void insert(string word) {
        Node* node = root ; // dummy node
        for(int i = 0 ; i < word.size() ; i++){
            if(!node -> contains_element(word[i])){
                Node* newnode = new Node() ; // make a new node for element if its not present

                node -> put(word[i],newnode) ; 
            }
            node = node -> get(word[i]) ; //move to the reference trie
        }
        node -> setEnd() ;
    }
    
    bool search(string word) {
        Node *temp = root ;
        for(int i = 0 ; i < word.size() ; i++){
            if(!temp->contains_element(word[i])){
                return false ;
            }
            temp =temp ->get(word[i]) ;
        }
        //return temp -> flag ;
        return temp -> isEnd() ;
    }
    
    bool startsWith(string prefix) {
        Node *temp = root ;
        for(int i = 0 ; i < prefix.size() ; i++){
            if(!temp->contains_element(prefix[i])){
                return false ;
            }
            temp =temp ->get(prefix[i]) ;
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */