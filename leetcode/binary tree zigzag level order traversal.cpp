#include <iostream>
#include <queue>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    	vector<vector<int> > ret;
    	if (!root) return ret;
    	
    	vector<int> v;
    	queue<TreeNode*> que;
    	que.push(root);
    	que.push(NULL);
    	while (!que.empty()) {
			TreeNode* top = que.front();
			que.pop();
			if (top) {
				v.push_back(top->val);
				if (top->left) que.push(top->left);
				if (top->right) que.push(top->right);
			}
			else {
				ret.push_back(v);
				v.clear();
				if (que.empty() || que.front() == NULL)
					break;
				que.push(NULL);
			}			
    	}
    	for (int i = 0; i < ret.size(); ++i){
    		if (i % 2 == 1)
    			reverse(ret[i].begin(), ret[i].end());
    	}
    	return ret;
    }
};

int main() {
	Solution s;
	TreeNode root(1, new TreeNode(2), new TreeNode(3));
	root.left = new TreeNode(4, new TreeNode(5), new TreeNode(6));
	root.right = new TreeNode(7, new TreeNode(8), new TreeNode(9));
	
	vector<vector<int> > ret = s.zigzagLevelOrder(&root);
	for (int i = 0; i < ret.size(); ++i){
		for (int j = 0; j < ret[i].size(); ++j){
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}