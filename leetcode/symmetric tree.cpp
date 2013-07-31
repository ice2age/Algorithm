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
	bool equal(TreeNode* tree1, TreeNode* tree2) {
		if (!tree1 && !tree2) return true;
		if (!tree1 || !tree2) return false;
		if (tree1->val != tree2->val) return false;
		return equal(tree1->left, tree2->right) && equal(tree1->right, tree2->left);
	}
	
	bool isSymmetric(TreeNode *root) {
    	if (!root) return true;
    	return equal(root->left, root->right);
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
	TreeNode tree(1, new TreeNode(2), new TreeNode(3));
	cout << s.isSymmetric(&tree);
	return 0;
}