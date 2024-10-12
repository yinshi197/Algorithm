#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;    //节点上的元素
    ListNode *next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//使用虚拟头节点，处理需要删除头节点的情况。(使原来的头节点变成非头节点)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;   //当前节点
        while(cur != NULL && cur->next != NULL)
        {
            if(cur->next->val == val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else cur = cur->next;
        }

        return dummyHead->next;
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

int main(int argc, char **argv)
{
    int a[]{1, 2, 6, 3, 4, 5, 6}; 
    ListNode *head = creatList(a, 7);
    Solution *so = new Solution();
    ListNode *ans = so->removeElements(head, 6);
    while(ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}