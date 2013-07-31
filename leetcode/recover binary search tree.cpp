#include <iostream>
#include <vector>
using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode*l=NULL,TreeNode*r=NULL) : val(x), left(l), right(r) {}
};

class Solution {
public:
	bool found;
	TreeNode *p1, *p2, *pre;

	void inorder(TreeNode* root) {
		if (found) return;
		if (!root) return;

		this->inorder(root->left);
		if (pre &&  pre->val > root->val) {
			if (p1)
				found = true;
			else
				p1 = pre;
			p2 = root;
		}
		pre = root;
		this->inorder(root->right);
	}

	void recoverTree_recursive(TreeNode *root) {
		found = false;
		p1 = p2 = pre = NULL;	
		this->inorder(root);
		if (p1 && p2) std::swap(p1->val, p2->val);
	}
	
	void recoverTree(TreeNode *root) {
		TreeNode *pre = NULL, *p1 = NULL, *p2 = NULL, *p;
		TreeNode *current = root;
		
		while (current != NULL){
			if (current->left == NULL) {
				if (pre && pre->val > current->val) {
					if (!p1) p1 = pre;
					p2 = current;
				}
				pre = current;
				current = current->right;
			}
			else {
				p = current->left;
				while (p->right != NULL && p->right != current)
					p = p->right;
				if (p->right == NULL){
					p->right = current;
					current = current->left;
				}
				else {
					p->right = NULL;
					if (pre && pre->val > current->val) {
						if (!p1) p1 = pre;
						p2 = current;
					}
					pre = current;
					current = current->right;
				}
			}
		}
		
		if (p1 && p2) std::swap(p1->val, p2->val);
	}
};


void inorder(TreeNode* tree) {
	if (!tree) return;
	inorder(tree->left);
	cout << tree->val << " ";
	inorder(tree->right);
}

int main() {
	Solution s;
	TreeNode tree(3, new TreeNode(1), new TreeNode(2));
	inorder(&tree); cout << endl;
	s.recoverTree(&tree);
	inorder(&tree); cout << endl;
	return 0;
}