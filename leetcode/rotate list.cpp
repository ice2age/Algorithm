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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k <= 0 || !head) return head;
        
        int n = 0;
        ListNode* cur = head, *pre;
        while (cur){
        	n++;
        	pre = cur;
        	cur = cur->next;
        }
        pre->next = head; // circular
        
        n -= k % n;
        if (n == 0) return head;
        cur = head;
        for (int i = 0; i < n; ++i){
        	pre = cur;
        	cur = cur->next;
        }
        pre->next = NULL;	// break
        return cur;
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
	L list(1, new L(2, new L(3, new L(4, new L(5)))));
	Solution s;
	traverse(s.rotateRight(&list, 2)); // 4 5 1 2 3
	return 0;
}