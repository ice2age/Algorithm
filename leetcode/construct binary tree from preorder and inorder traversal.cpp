#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode*l=NULL, TreeNode*r=NULL) : val(x), left(l), right(r) {}
};

class Solution {
public:
	TreeNode* build(int* left, int* right, int n) {
		if (n == 0) return NULL;
		TreeNode* root = new TreeNode(right[0]);
		if (n == 1) return root;

		int* it = find(left, left+n, right[0]);
		int m = it - left;
		root->left = build(left, right+1, m);
		root->right = build(left+m+1, right+1+m, n-m-1);
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return build(&inorder[0], &preorder[0], inorder.size());
	}
};

void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void postorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	inorder(root->right);
	cout << root->val << " ";
}

int main() {
	Solution s;
	vector<int> in;
	in.push_back(4);
	in.push_back(2);
	in.push_back(1);
	in.push_back(3);
	in.push_back(5);

	vector<int> pre;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(3);
	pre.push_back(5);

	TreeNode* tree = s.buildTree(pre, in);
	postorder(tree);
	return 0;
}