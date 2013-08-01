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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int c = 0, s;
		ListNode list(0), *pre = &list, *tmp;
		while (l1 && l2){
			s = c + l1->val + l2->val;
			c = s / 10;
			s %= 10;
			l1->val = s;
			pre->next = l1;
			l1 = l1->next;
			l2 = l2->next;
			pre = pre->next;
		}
		tmp = (!l1 ? l2 : l1);
		while (tmp) {
			s = c + tmp->val;
			c = s / 10;
			s %= 10;
			tmp->val = s;
			pre->next = tmp;
			tmp = tmp->next;
			pre = pre->next;
		}
		if (c) pre->next = new ListNode(c);
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
	L a(2, new L(4, new L(3)));
	L b(5, new L(6, new L(4)));
	
	Solution s;
	traverse(s.addTwoNumbers(&a, &b));
	
	return 0;
}