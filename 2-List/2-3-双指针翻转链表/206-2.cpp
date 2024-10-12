//递归实现
#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;    //节点上的元素
    ListNode *next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }

    ListNode* reverse(ListNode *pre, ListNode *cur)
    {
        if(cur == NULL) return pre;
        ListNode *temp = cur->next;
        cur->next = pre;
        
        return reverse(cur, temp);
    }
};

ListNode* creatList(int a[], int n)
{
    ListNode *head = new ListNode(a[0]);
    ListNode *temp = head;

    for(int i = 1; i < n; i++)
    {
        ListNode *newNode = new ListNode(a[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

void printList(ListNode *list)
{
    ListNode *cur = list;
    while(cur != nullptr)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int a[]{1, 2, 3, 4, 5, 6, 7}; 
    ListNode *head = creatList(a, 7);
    printList(head);
    Solution *so = new Solution();
    ListNode * ret = so->reverseList(head);
    printList(ret);
    return 0;
}