/**********************************************************************************
*
* Given a binary tree, find the maximum path sum.
*
* The path may start and end at any node in the tree.
*
* For example:
* Given the below binary tree,
*
*        1
*       / \
*      2   3
*
* Return 6.
*
*
**********************************************************************************/

#include<iostream	>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};
//The solution is quite simple can be explained by itself 
int maxPathSum(TreeNode*root, int &maxSum)
{
	if (NULL == root)return 0;

	//get the max PathSum for both left and right branch 
	int left = maxPathSum(root->left, maxSum);   //左子树或者有子树 最大的和的路径
	int right = maxPathSum(root->right, maxSum);

	// The max sum could be one of the following situations:
	//    1) root + left
	//    2) root + right
	//    3) root
	//    4) root + left + right   
	//
	// And the whole function need to return the the max of 1) 2) 3) 
	int val = root->val;
	int maxBranch = left > right ? max(left + val, val) : max(right + val, val);   //左孩子+根节点、右孩子+根节点，根节点 选出最大的和
	int m = max(left + right + val, maxBranch);  // 左右孩子＋根节点  、  左孩子+根节点  、  右孩子加根节点    和最大的值

	maxSum = max(maxSum, m);//m 跟 目前最大的maxSum 比  

	return maxBranch; //返回 根节点左或右子树最大的 和
}

int maxPathSum(TreeNode*root)
{
	#define INT_MIN (-2147483647);
	int maxSum = INT_MIN;
	maxPathSum(root, maxSum);
	return maxSum;
}


int main()
{
	TreeNode root(1);
	TreeNode left(-1);
	TreeNode right(-3);
	root.left = &left;
	root.right = &right;
	cout << maxPathSum(&root) << endl;

	return 0;



}







