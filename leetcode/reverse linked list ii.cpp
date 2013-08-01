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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode list(0);
        list.next = head;
        ListNode *pre = &list;
        ListNode *pm, *cur = head, *tmp;
        int i;
        for (i = 1; i < m; ++i) {
        	pre = cur;
        	cur = cur->next;
        }
        pm = cur;
        
        i++;
        cur = cur->next;
        for (; i <= n; ++i){
        	tmp = cur->next;
        	cur->next = pre->next;
        	pre->next = cur;
        	cur = tmp;
        }
        pm->next = cur;
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
	ListNode l(1), *cur = &l;
	for (int i = 2; i <= 10; ++i){
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	
	Solution s;
	int m, n;
	while (cin >> m >> n)
		traverse(s.reverseBetween(&l, m, n));
	return 0;
}