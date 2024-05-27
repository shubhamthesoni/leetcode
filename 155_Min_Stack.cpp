class MinStack {
    stack<pair<int,int>> S;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(S.empty())
        {
          S.push({val,val});
        }
        else
        {
          S.push({val, min(val, S.top().second)});
        }
    }
    
    void pop() {
        S.pop();
    }
    
    int top() {
        return S.top().first;
    }
    
    int getMin() {
        return S.top().second;
    }
};
