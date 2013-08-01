#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n=NULL) : val(x), next(n) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy, *cur = head, *tmp;
        int i = 0;
        while (cur && cur->next) {
        	tmp = cur->next->next;
        	pre->next = cur->next;
        	cur->next->next = pre = cur;
        	cur->next = tmp;
        	
        	cur = tmp;
        }
        return dummy.next;
    }
};

void traverse(ListNode* l) {
	while (l != NULL){
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}

int main() {
	typedef ListNode L;
	L list(1, new L(2, new L(3, new L(4))));
	Solution s;
	traverse(s.swapPairs(&list));
	return 0;
}