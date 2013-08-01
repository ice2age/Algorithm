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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        int cnt = 0;
        ListNode *cur = head, *pre = &dummy;
        while (cur){
        	cur = cur->next;
        	cnt++;
        }
        
        n = cnt - n;
        for (cnt = 0, cur = head; cnt < n; ++cnt){
        	pre = cur;
        	cur = cur->next;
        }
        pre->next = cur->next;
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
	traverse(s.removeNthFromEnd(&list, 2)); // 1, 2, 4
	return 0;
}