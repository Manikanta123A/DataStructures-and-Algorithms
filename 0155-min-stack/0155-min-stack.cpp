class MinStack {
public:
    stack<int> s;
    stack<int> s2;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(s2.empty() || s2.top()>=value ){
            s2.push(value);
        }
    }
    
    void pop() {
        int val = s.top();
        if ( s2.top()>= val){
            s2.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s2.top();
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