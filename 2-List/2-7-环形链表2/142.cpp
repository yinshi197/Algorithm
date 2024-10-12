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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow= head;
        while(fast != nullptr && fast->next != nullptr)
        {
            //先移动再判断
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                ListNode *index1 = fast;    //相遇节点
                ListNode *index2 = head;    //头节点
                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index1; 
            }
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
    ListNode *ret = so->detectCycle(test1);
    printList(ret);
    return 0;
}