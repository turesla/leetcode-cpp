/**********************************************************************************
*
* Write a program to find the node at which the intersection of two singly linked lists begins.
*
* For example, the following two linked lists:
*
*
*    A:          a1 ¡ú a2
*                       ¨K
*                         c1 ¡ú c2 ¡ú c3
*                       ¨J
*    B:     b1 ¡ú b2 ¡ú b3
*
* begin to intersect at node c1.
*
* Notes:
*
* If the two linked lists have no intersection at all, return null.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.
*
**********************************************************************************/
#include<iostream>
#include<cstdlib>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
	ListNode*getIntersectionNode(ListNode*headA, ListNode*headB)
	{
		//caculate the length the length of each list 
		int lenA = getListLength(headA);
		int lenB = getListLength(headB);

		if (lenA<=0||lenB<=0)
		{
			return NULL;
		}

		//let List A is the longest List ;
		if (lenA<lenB)
		{
			swap(headA, headB);
		}
		 
		//move head of list A, make both of lists are same length 
		for (int i = 0; i < abs(lenA-lenB); i++)
		{
			headA = headA->next;
		}

		//synced travel both of lists and check their nodes are same or not ;
		while (headA!=headB)
		{
			headA = headA->next;
			headB = headB->next;
		}
		return headA;
	}



private:
	inline int getListLength(ListNode*head)
	{
		int len = 0;
		while (head!=NULL)
		{
			head = head->next;
			len++;
		}
		return len;
	}
};






















