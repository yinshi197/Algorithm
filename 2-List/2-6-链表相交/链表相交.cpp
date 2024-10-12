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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;
        while(curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }

        while(curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;

        if(lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;
        while(gap--)  curA = curA->next;

        while(curA != nullptr)
        {
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
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

//创建相交的链表
void createIntersectingLists(ListNode *headA, int valueA, ListNode *headB, int valueB ) {
    ListNode *curA = headA;
    ListNode *curB = headB;

    valueA--;
    valueB--;
    while(valueA--) curA = curA->next;
    while(valueB--) curB = curB->next;
    curB->next = curA->next;    
}


int main(int argc, char **argv)
{
    int a[]{4,1,8,4,5};
    int b[]{5,0,1,8,4,5};
    ListNode *test1 = creatList(a, sizeof(a) / sizeof(int));
    ListNode *test2 = creatList(b, sizeof(b) / sizeof(int));
    createIntersectingLists(test1, 2, test2, 3);
    Solution *so = new Solution();
    ListNode *ret = so->getIntersectionNode(test1, test2);
    printList(ret);
    return 0;
}