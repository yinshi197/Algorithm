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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        while(fast != nullptr)
        {
            fast = fast->next;
            if(n < 0)
            {
                slow = slow->next;
            }
            n--;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        temp = nullptr;

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
    ListNode *ret = so->removeNthFromEnd(test, 2);
    printList(ret);
    return 0;
}