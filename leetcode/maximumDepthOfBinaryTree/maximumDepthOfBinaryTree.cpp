
/**********************************************************************************
*
* Given a binary tree, find its maximum depth.
*
* The maximum depth is the number of nodes along the longest path from the root node
* down to the farthest leaf node.
*
**********************************************************************************/
#include<iostream>
#include<algorithm>

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	Solution();
	~Solution();

	int	MaxDepth (TreeNode*root )
	{
		if (root==NULL)
		{
			return 0;
		}
		if (!root->left&&!root->right)
		{
			return 1; 
		}

		int left = 1, right = 1; 
		if (root->left)
		{
			left += MaxDepth(root->left);		
		}
		if (root->right)
		{
			right += MaxDepth(root->right);
		}

		return left > right ? left : right;

	}
	

private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}


class Solution2 {
	int maxDepth(TreeNode*root)
	{
		if (root ==NULL)
		{
			return 0;
		}

		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};








