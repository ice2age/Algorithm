#include <iostream>
#include <vector>
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
	
	void inorder(TreeNode* root, vector<int>& v) {
		if (!root) return;
		inorder(root->left, v);
		v.push_back(root->val);
		inorder(root->right, v);
	}

    vector<int> inorderTraversal(TreeNode *root) {
    	vector<int> v;
    	inorder(root, v);
    	return v;
    }
};

int main() {
	Solution s;
	TreeNode root(1, new TreeNode(2), new TreeNode(3));
	root.left = new TreeNode(4, new TreeNode(5), new TreeNode(6));
	//root.right = new TreeNode(7, new TreeNode(8), new TreeNode(9));
	
	vector<int> ret = s.inorderTraversal(&root);
	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i] << " ";
	return 0;
}