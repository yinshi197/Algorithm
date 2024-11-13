#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if(out_stack.empty())
        {
            while(!in_stack.empty())
            {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        
        int ret = out_stack.top();
        out_stack.pop();
        return ret;
    }
    
    int peek() {
        int ret = this->pop();
        out_stack.push(ret);
        return ret;
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();        
    }

private:
    stack<int> in_stack;
    stack<int> out_stack;
};
int main()
{
    MyQueue *queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    queue->peek();  // 返回 1
    queue->pop();   // 返回 1
    queue->empty(); // 返回 false

    return 0;
}