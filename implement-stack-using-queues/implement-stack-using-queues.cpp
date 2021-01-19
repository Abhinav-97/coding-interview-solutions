class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int c = 0;
        while(c < q.size()-1)
        {
            int top = q.front();
            q.pop();
            q.push(top);
            c++;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = q.front();
        q.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
​
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
