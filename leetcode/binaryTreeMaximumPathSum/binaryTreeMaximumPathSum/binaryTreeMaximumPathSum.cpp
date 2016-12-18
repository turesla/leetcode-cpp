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
	int left = maxPathSum(root->left, maxSum);   //���������������� ���ĺ͵�·��
	int right = maxPathSum(root->right, maxSum);

	// The max sum could be one of the following situations:
	//    1) root + left
	//    2) root + right
	//    3) root
	//    4) root + left + right   
	//
	// And the whole function need to return the the max of 1) 2) 3) 
	int val = root->val;
	int maxBranch = left > right ? max(left + val, val) : max(right + val, val);   //����+���ڵ㡢�Һ���+���ڵ㣬���ڵ� ѡ�����ĺ�
	int m = max(left + right + val, maxBranch);  // ���Һ��ӣ����ڵ�  ��  ����+���ڵ�  ��  �Һ��ӼӸ��ڵ�    ������ֵ

	maxSum = max(maxSum, m);//m �� Ŀǰ����maxSum ��  

	return maxBranch; //���� ���ڵ�������������� ��
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






