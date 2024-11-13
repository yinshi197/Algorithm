#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size() - 1;
        while(size--)
        {
            que2.push(que1.front());
            que1.pop();
        }

        int ret = que1.front();
        que1.pop();

        que1 = que2;
        while(!que2.empty())
        {
            que2.pop();
        }

        return ret;
    }
    
    int top() {
        int size = que1.size() - 1;
        while(size--)
        {
            que2.push(que1.front());
            que1.pop();
        }

        int ret = que1.front();
        que2.push(ret);
        que1.pop();

        que1 = que2;
        while(!que2.empty())
        {
            que2.pop();
        }

        return ret;
    }
    
    bool empty() {
        return que1.empty();
    }

private:
    queue<int> que1;
    queue<int> que2;
};
int main()
{
    MyStack *stack = new MyStack();
    stack->push(1);        
    stack->push(2);        
    stack->pop();   // 注意弹出的操作       
    stack->push(3);        
    stack->push(4);       
    stack->pop();  // 注意弹出的操作    
    stack->pop();    
    stack->pop();    
    stack->empty(); 

    return 0;
}