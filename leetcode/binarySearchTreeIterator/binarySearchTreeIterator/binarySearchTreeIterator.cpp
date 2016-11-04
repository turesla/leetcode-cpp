/**********************************************************************************
*
* Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
*
* Calling next() will return the next smallest number in the BST.
*
* Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*
**********************************************************************************/

#include<iostream>
#include<vector>
using namespace std;






 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class BSTIterator {
private:
	vector<int> v;
	int pos;
public:
	//Travse the tree in-order and covert it to the array
	BSTIterator(TreeNode *root)
	{
		pos = 0;
		vector<TreeNode*> stack;
		while (stack.size() > 0 || root != NULL)
		{
			if (root) {
				stack.push_back(root);
				root = root->left;
			}
			else {
				root = stack.back();
				stack.pop_back();
				v.push_back(root->val);
				root = root->right;
			}
		}
	}
	/*@return whether we have a next smallest number */
	bool hasNext()
	{
		return pos < v.size();
	}

	/*@return the next smallest number */
	int next() {
		return v[pos++];
	}

	
};










