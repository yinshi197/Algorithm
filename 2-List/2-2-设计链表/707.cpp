
#include <iostream>
#include <cmath>
using namespace std;

// struct ListNode {
//     int val;    //节点上的元素
//     ListNode *next; //指向下一个节点的指针
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class MyLinkedList {
public:
    struct ListNode {
        int val;    //节点上的元素
        ListNode *next; //指向下一个节点的指针
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    MyLinkedList() {
        dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index > (_size - 1) || index < 0)
        {
            return -1;
        }
        ListNode *cur = dummyHead->next;
        //后缀--表达式计算完再--
        while(index--) cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode *newNode = new ListNode(val,dummyHead->next);
        dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummyHead;
        while(cur->next != nullptr) cur = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return;
        if(index == _size)
        {
            addAtTail(val);
            return;
        }
        if(index < 0) index = 0;
        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummyHead;
        while(index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
        
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) return;
        ListNode *cur = dummyHead;
        while(index--)
        {
            cur = cur->next;
        }
        ListNode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr; //避免产生野指针
        _size--;
        
        return;
    }

    void printList()
    {
        ListNode *cur = dummyHead;
        while(cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    ListNode *dummyHead;
};

// ListNode* creatList(int a[], int n)
// {
//     ListNode *head = new ListNode(a[0]);
//     ListNode *temp = head;

//     for(int i = 1; i < n; i++)
//     {
//         ListNode *newNode = new ListNode(a[i]);
//         temp->next = newNode;
//         temp = newNode;
//     }

//     return head;
// }

int main(int argc, char **argv)
{
    // int a[]{1, 2, 6, 3, 4, 5, 6}; 
    // ListNode *head = creatList(a, 7);
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->printList();
    myLinkedList->addAtHead(7);
    myLinkedList->addAtHead(2);
    myLinkedList->addAtHead(1);
    myLinkedList->printList();
    myLinkedList->addAtIndex(3,0);
    myLinkedList->printList();
    myLinkedList->deleteAtIndex(2);
    myLinkedList->printList();
    myLinkedList->addAtHead(6);
    myLinkedList->addAtTail(4);
    myLinkedList->get(4);
    myLinkedList->printList();
    myLinkedList->deleteAtIndex(4);
    myLinkedList->addAtHead(4);
    myLinkedList->addAtIndex(5,0);
    myLinkedList->addAtHead(6);
    myLinkedList->printList();


    return 0;
}