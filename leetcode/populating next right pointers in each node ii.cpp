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
			TreeLinkNode* pre = NULL;
			TreeLinkNode* cur = lead;
			lead = NULL;
			while (cur != NULL) {
				if (!lead && cur->left)
					lead = cur->left;
				if (!lead && cur->right)
					lead = cur->right;
				
				if (cur->left) {
					if (pre) pre->next = cur->left;
					pre = cur->left;
				}
				if (cur->right){
					if (pre) pre->next = cur->right;
					pre = cur->right;
				}
				cur = cur->next;
			}
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