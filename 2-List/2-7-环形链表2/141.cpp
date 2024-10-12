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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }

        return false;
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

void createCycleList(ListNode *head, int index)
{
    ListNode *flag = head;
    ListNode *cur = head;
    while(cur->next != nullptr)
    {
        if(index > 0)
        {
            index--;
            flag = cur;
        }
        cur = cur->next;
    } 

    cur->next = flag;
}

int main(int argc, char **argv)
{
    int a[]{3,2,0,-4};
    ListNode *test1 = creatList(a, sizeof(a) / sizeof(int));
    createCycleList(test1, 1);
    Solution *so = new Solution();
    bool ret = so->hasCycle(test1);
    cout << ret << endl;
    return 0;
}