//回纹链表
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct ListNode {
    int val;    //节点上的元素
    ListNode *next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode *rev = reverseList(head, vec);
        int i = 0;
        while(rev != NULL)
        {
            if(rev->val != vec[i++]) return false;
            rev = rev->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head, vector<int> &vec) {
        ListNode *temp = nullptr;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur != nullptr)
        {
            vec.push_back(cur->val);
            temp = cur->next;   //修改cur->next前先保存一下
            cur->next = pre;
        
            //更新
            pre = cur;
            cur = temp;
        }

        return pre;
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
    int a[]{1, 2, 2, 1}; 
    ListNode *head = creatList(a, 4);
    Solution *so = new Solution();
    bool ret = so->isPalindrome(head);
    cout << ret << endl;
    return 0;
}