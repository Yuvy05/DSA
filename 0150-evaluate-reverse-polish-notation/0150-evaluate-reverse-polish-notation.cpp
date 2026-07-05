class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st ;
        int x , y ;
        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+"){
                x=stoi(st.top()) ; st.pop();
                y = stoi(st.top()) ; st.pop() ;
                st.push(to_string(x+y)) ;
            }
            else if(tokens[i] == "-"){
                x=stoi(st.top()) ; st.pop();
                y = stoi(st.top()) ; st.pop() ;
                st.push(to_string(-x+y)) ;
            }
            else if(tokens[i] == "*"){
                x=stoi(st.top()) ; st.pop();
                y = stoi(st.top()) ; st.pop() ;
                st.push(to_string(x*y)) ;
            }
            else if(tokens[i] == "/"){
                x=stoi(st.top()) ; st.pop();
                y = stoi(st.top()) ; st.pop() ;
                st.push(to_string(y/x)) ;
            }
            else st.push(tokens[i]) ;
        }  
        return stoi(st.top()) ;
    }
};