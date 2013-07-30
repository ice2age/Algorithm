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
		TreeNode* root = new TreeNode(right[n-1]);
		if (n == 1) return root;

		int* it = find(left, left+n, right[n-1]);
		int m = it - left;
		root->left = build(left, right, m);
		root->right = build(left+m+1, right+m, n-m-1);
		return root;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return build(&inorder[0], &postorder[0], inorder.size());
	}
};

void inorder(TreeNode* root) {
	if (!root) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main() {
	Solution s;
	vector<int> in;
	in.push_back(4);
	in.push_back(2);
	in.push_back(1);
	in.push_back(3);
	in.push_back(5);

	vector<int> post;
	post.push_back(4);
	post.push_back(2);
	post.push_back(5);
	post.push_back(3);
	post.push_back(1);

	TreeNode* tree = s.buildTree(in, post);
	inorder(tree);
	return 0;
}