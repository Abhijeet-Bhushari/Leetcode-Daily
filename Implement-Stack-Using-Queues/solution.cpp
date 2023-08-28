class MyStack {
public:
    queue<int> q1;  // Primary queue for stack operations
    queue<int> q2;  // Temporary queue for rearranging elements
    
public:
    MyStack() {
        // Constructor, no specific initialization needed
    }
    
    void push(int x) {
        q1.push(x);  // Simply push the element onto the primary queue
    }
    
    int pop() {
        if (q1.empty())
            return -1;  // If the stack is empty, return a default value
        
        // Move all but the last element from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int t = q1.front();  // Store the last element in q1
        q1.pop();  // Remove the last element from q1
        
        swap(q1, q2);  // Swap the roles of q1 and q2 (q2 becomes empty)
        return t;  // Return the popped element
    }
    
    int top() {
        if (q1.empty())
            return -1;  // If the stack is empty, return a default value
        
        // Move all but the last element from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int t = q1.front();  // Store the last element in q1
        q2.push(q1.front());  // Push the last element to q2
        q1.pop();  // Remove the last element from q1
        
        swap(q1, q2);  // Swap the roles of q1 and q2 (q2 becomes empty)
        return t;  // Return the top element
    }
    
    bool empty() {
        return q1.empty();  // Check if the primary queue is empty
    }
};
