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
        ListNode* cur = head, *pre = NULL;
        while (cur){
        	if (pre && pre->val == cur->val){
        		pre->next = cur->next;
        	}
        	else
        		pre = cur;
        	cur = cur->next;
        }
        return head;
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