class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    int m = INT_MAX;
    MinStack() {
    }
    
    void push(int x) {
        if(x <= m){ //note it's <=, not <!
            //2nd smallest value is under 1st smallest value
            stk.push(m);
            m = x;
        }
        stk.push(x);
    }
    
    void pop() {
        int tmp = stk.top();
        stk.pop();
        //pop 2nd smallest value along 1st smallest value
        if(tmp == m){
            //when pop 1st smallest value
            //update m to 2nd smallest value
            m = stk.top();
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return m;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */