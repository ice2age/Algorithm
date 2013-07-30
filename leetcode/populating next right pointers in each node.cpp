#include <iostream>
#include <queue>
using namespace std;


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode* lead) {
		while (lead){
			TreeLinkNode* cur = lead;
			while (cur != NULL) {
				if (cur->left) {
					cur->left->next = cur->right;
					if (cur->next)
						cur->right->next = cur->next->left;						
				}
				cur = cur->next;
			}
			lead = lead->left;
		}
	}
};

int main() {
	Solution s;

	TreeLinkNode root(1);
	TreeLinkNode left(2);
	TreeLinkNode right(3);
	root.left = &left;
	root.right = &right;
	root.next = NULL;
	s.connect(&root);

	return 0;
}