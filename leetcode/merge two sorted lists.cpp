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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *h = NULL, *t = NULL;
        while (l1 && l2){
        	if (l1->val < l2->val){
        		if (!h) h = l1;
        		else t->next = l1;
        		t = l1;
        		l1 = l1->next;
        	}
        	else {
        		if (!h) h = l2;
        		else t->next = l2;
        		t = l2;
        		l2 = l2->next;
        	}
        }
        if (l1) t->next = l1;
        if (l2) t->next = l2;
        return h;
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
	Solution s;
	ListNode l1(1, new ListNode(4));
	ListNode l2(2, new ListNode(3));
	
	traverse(s.mergeTwoLists(&l1, &l2));
	
	return 0;
}