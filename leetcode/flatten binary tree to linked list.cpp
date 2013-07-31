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
	void preorder(TreeNode* root, vector<TreeNode*>& v) {
		if (!root) return;
		v.push_back(root);
		preorder(root->left, v);
		preorder(root->right, v);
	}

	void flatten(TreeNode *root) {
		vector<TreeNode*> v;
		preorder(root, v);
		int n = v.size();
		for (int i = 0; i < n-1; ++i){
			v[i]->left = NULL;
			v[i]->right = v[i+1];
		}
		if (!v.empty()){
			TreeNode* last = v.back();
			last->left = last->right = NULL;
		}
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
	inorder(&tree); cout << endl;
	s.flatten(NULL);
	inorder(&tree); cout << endl;
	return 0;
}