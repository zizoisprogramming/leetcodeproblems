
 // Definition for singly-linked list.
 struct ListNode {
    int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* ptr = nullptr;
        while(temp && temp->val == val)
        {
            head = temp->next;
            delete temp;
            temp = head;
        }
        if(temp && temp->next)
        {
            ptr = temp->next;
            while(ptr->next)
            {
                if(ptr->val == val)
                {
                    temp->next = ptr->next;
                    delete ptr;
                    ptr = temp->next;
                }
                else
                {
                    temp = temp->next;
                    ptr = ptr->next;
                }
            }

            if(ptr->val == val)
            {
                temp->next = nullptr;
                delete ptr;
                ptr = nullptr;
            }
        }
        return head;
    }
};