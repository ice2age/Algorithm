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
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode *start=head, *cur = head, *pre = &dummy;
		while (cur) {
			int i;
			for (i = 0; i < k-1 && cur; ++i, cur=cur->next)
				;
			if (i != k-1 || !cur) break;
			pre->next = cur;
			pre = start;
			ListNode* n = cur->next, *tmp;
			while (start != cur) {
				tmp = start->next;
				start->next = cur->next;
				cur->next = start;
				start = tmp;
			}
			start = cur = n;
		}
		return dummy.next;
	}
};

void traverse(ListNode* head) {
	for (; head; head = head->next){
		cout << head->val << " ";
	}
	cout << endl;
}

int main() {
	Solution s;
	typedef ListNode L;
	L list(1, new L(2, new L(3, new L(4, new L(5)))));
	traverse(&list);
	int k;
	while (cin >> k){
		traverse(s.reverseKGroup(&list, k));
	}
	return 0;
}