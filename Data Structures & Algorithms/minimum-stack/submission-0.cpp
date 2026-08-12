class MinStack {
public:
    stack<int>st;
    map<int,int>freq;
    int mn;
    MinStack() {
        mn=INT_MAX;
    }
    
    void push(int val) {
        st.push(val);
        freq[val]++;
    }
    
    void pop() {
        freq[st.top()]--;
        if(freq[st.top()] == 0){freq.erase(st.top());}
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return freq.begin()->first;
    }
};
