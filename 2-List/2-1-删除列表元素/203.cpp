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
    ListNode* removeElements(ListNode* head, int val) {
        //删除头节点
        while(head != NULL && head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        //删除非头节点
        ListNode *cur = head;   //当前节点
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

        return head;
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
    int a[]{7, 7, 7, 7}; 
    ListNode *head = creatList(a, 4);
    Solution *so = new Solution();
    ListNode *ans = so->removeElements(head, 7);
    while(ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}