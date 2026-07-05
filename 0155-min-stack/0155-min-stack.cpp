class MinStack {
public:
    stack<long long>st ;
    long long mn ;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            mn = value ;
            st.push(value) ;
        }
        else if(value < mn){
            long long newval = 2LL*value - mn ;
            st.push(newval) ;
            mn = value ;
        }
        else st.push(value) ;
    }
    
    void pop() {
        if(st.top() < mn){
            mn = 2LL*mn - st.top() ;
            st.pop() ;
        }
        else st.pop() ;
    }
    
    int top() {
        if(st.top() < mn){
            return mn ;
        }
        return st.top() ;
    }
    
    int getMin() {
        return mn ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */