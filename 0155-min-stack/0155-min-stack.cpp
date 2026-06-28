class MinStack {
public:
    long long int mn = INT_MAX ;
    stack<long long int>s ;
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            mn = value ;
            s.push(value);
        }
        else if(value >= mn) s.push(value) ;
        else{
            long long int newval = 2LL*value - mn ;
            mn = value ;
            s.push(newval) ;
        }
    }
    
    void pop() {
        if(s.empty()) return ;
        if(mn > s.top()){
            long long int x = s.top() ;
            s.pop() ;
            mn= 2*mn - x ;
        }
        else{
            s.pop() ;
        }
    }
    
    int top() {
        if (s.empty()) return INT_MAX;
        if(s.top() < mn) return mn ;
        else return s.top() ;
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