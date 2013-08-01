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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode list(0);
        list.next = head;
        ListNode* pre = &list, *cur = head, *next;
        while (cur){
        	next = cur->next;
        	while (next && cur->val == next->val)
        		next = next->next;
        	if (cur->next == next)
        		pre = cur;
        	else
        		pre->next = next;
        	cur = next;
        }
        return list.next;
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
	L l(1, new L(1, new L(2, new L(3, new L(3)))));
	
	Solution s;
	traverse(s.deleteDuplicates(&l));
	
	return 0;
}