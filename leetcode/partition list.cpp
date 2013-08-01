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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *lh = NULL, *lt = NULL;
        ListNode *rh = NULL, *rt = NULL;
        ListNode * cur = head;
        while (cur){
        	if (cur->val < x){
        		if (!lh) lh = cur;
        		else lt->next = cur;
        		lt = cur;
        	}
        	else {
        		if (!rh) rh = cur;
        		else rt->next = cur;
        		rt = cur;
        	}
        	cur = cur->next;
        }
        if (!lh) {
        	rt->next = NULL;
        	return rh;
        }
        if (!rh) {
        	lt->next = NULL;
        	return lh;
        }
        lt->next = rh;
        rt->next = NULL;
        return lh;
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
	ListNode l(1), *cur = &l;
	for (int i = 0; i < 10; ++i){
		cur->next = new ListNode(rand() % 10);
		cur = cur->next;
	}
	traverse(&l);
	
	Solution s;
	int x;
	cin >> x;
	traverse(s.partition(&l, x));
	return 0;
}