#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *temp1 = cur->next; //1号节点
            ListNode *temp2 = cur->next->next;  //2号节点

            //技巧：按照原来节点顺序更新节点的next, 0 1 2  
            cur->next = temp2;  //步骤1
            temp1->next = temp2->next;  //步骤2  
            temp2->next = temp1;    //步骤3

            //更新,一次更新两个节点
            cur = cur->next->next;
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
    int a[]{1,2,3,4,5,6};
    ListNode *test = creatList(a, sizeof(a) / sizeof(int));
    Solution *so = new Solution();
    ListNode *ret = so->swapPairs(test);
    printList(ret);
    return 0;
}