#include <iostream>
#include <queue>
using namespace std;


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l = NULL, TreeNode* r = NULL) : val(x), left(l), right(r) {}
};

class Solution {
public:
	typedef pair<TreeNode*, int> QType;
	int minDepth(TreeNode *root) {
		if (!root) return 0;
		queue<QType> que;
		que.push(make_pair(root, 1));
		while (!que.empty()){
			QType top = que.front();
			que.pop();
			if (!top.first->left && !top.first->right)
				return top.second;

			if (top.first->left)
				que.push(make_pair(top.first->left, top.second+1));	
			if (top.first->right)
				que.push(make_pair(top.first->right, top.second+1));
		}
		return 0;
	}
};

int main() {
	TreeNode root(1, NULL, new TreeNode(3));
	Solution s;
	cout << s.minDepth(&root);	

	return 0;
}