#include<iostream>

using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int val){
            this->val = val;
            this->next = nullptr;
        }
};



class Solution{
    public: 
        ListNode* reverse(ListNode* head){
            ListNode* result = nullptr;
            while(head != nullptr){
                ListNode* tmp = head->next;
                head->next = result;
                result = head;
                head = tmp;
            }

            return result;
        }       
};

class Solution2{
    public:
        ListNode * fresult = nullptr;
        ListNode* helper(ListNode *head){
            if(head == nullptr){
                return head;
            }
            if(head->next == nullptr){
                fresult = head;
                return head;
            }
            ListNode *result = helper(head->next);
            head->next = nullptr;
            result->next = head;
            /* ListNode *result = helper(head->next);
               head->next->next = head;
               head->next = nullptr;
               return result*/
            return head;
        }

        ListNode* reverse(ListNode* head){
            helper(head);
            return fresult;
        }
};


int main(){
    ListNode *head, *p;
    head = new ListNode(1);
    p = head;
    for(int i = 2; i <= 4; i++){
        ListNode *s = new ListNode(i);
        p->next = s;
        p = s;
    }

    // Solution s =  Solution();
    Solution2 s  = Solution2();
    ListNode * result = s.reverse(head);
    for(int i = 0; i < 4; i++){
        cout << result->val;
        result = result->next;
    }
}