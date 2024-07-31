#define ll long long
class MinStack {
    ll mini = INT_MAX;
    stack<ll> st;
public:
    MinStack() {
        while (!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val) {
        if (st.size() == 0) {
            st.push(val);
            mini = val;
        } else {
            if (val < mini) {
                st.push(1LL * 2 * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        ll top_val = st.top();
        if (top_val >= mini) {
            st.pop();
        } else {
            st.pop();
            mini = 2 * mini - top_val;
        }
    }
    
    int top() {
        ll top_val = st.top();
        if (top_val >= mini) {
            return top_val;
        } else {
            return mini;
        }
    }
    
    int getMin() {
        return mini;
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