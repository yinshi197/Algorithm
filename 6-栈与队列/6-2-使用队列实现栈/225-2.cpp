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
        int ret;
        while(size--)
        {
            que1.push(que1.front());
            que1.pop();
        }
        
        ret = que1.front();
        que1.pop();

        return ret;
    }
    
    int top() {
        int size = que1.size() - 1;
        int ret;
        while(size--)
        {
            que1.push(que1.front());
            que1.pop();
        }
        
        ret = que1.front();
        que1.push(que1.front());
        que1.pop(); //确保数据顺序不变

        return ret;
    }
    
    bool empty() {
        return que1.empty();
    }

private:
    queue<int> que1;
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