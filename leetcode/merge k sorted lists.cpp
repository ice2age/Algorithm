#include <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n=NULL) : val(x), next(n) {}
};

class Solution {
public:
	ListNode* getMinimal(vector<ListNode*>& lists) {
		ListNode* min = NULL;
		int index = 0;
		for (int i = 0; i < lists.size(); ++i) {
			if (lists[i]){
				if (!min || lists[i]->val < min->val){
					min = lists[i];
					index = i;
				}
			}
		}
		if (min){
			lists[index] = min->next;
		}
		return min;
	}
	
	ListNode *mergeKLists(vector<ListNode *> &lists) {
    	ListNode dummy(0);
    	ListNode* pre = &dummy, *cur;
    	while ((cur = this->getMinimal(lists)) != NULL){
    		pre->next = cur;
    		pre = cur;
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
	Solution s;
	typedef ListNode L;
	ListNode* a[] =  {new L(1, new L(4)), new L(2, new L(5)), new L(3, new L(6)) };
	vector<ListNode*> v(a, a+3);
	traverse(s.mergeKLists(v));
	return 0;
}