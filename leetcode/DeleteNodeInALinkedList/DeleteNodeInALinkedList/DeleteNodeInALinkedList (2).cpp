/**********************************************************************************
*
* Write a function to delete a node (except the tail) in a singly linked list, given
* only access to that node.
*
* Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with
* value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*
**********************************************************************************/
#include<iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
	//because the deleted is not the tail 
	//so , we can move the content of next node to this one ,and delete next time 

	void deleteNode(ListNode*node)
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}




};
