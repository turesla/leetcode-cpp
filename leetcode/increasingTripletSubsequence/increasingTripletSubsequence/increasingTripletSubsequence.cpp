/***************************************************************************************
*
* Given an unsorted array return whether an increasing subsequence of length 3 exists
* or not in the array.
*
* Formally the function should:
* Return true if there exists i, j, k
* such that arr[i] < arr[j] < arr[k] given 0 �� i < j < k �� n-1 else return false.
* Your algorithm should run in O(n) time complexity and O(1) space complexity.
*
* Examples:
* Given [1, 2, 3, 4, 5],
* return true.
*
* Given [5, 4, 3, 2, 1],
* return false.
*
***************************************************************************************/

#include<vector>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>&nums)
	{
		bool solution = false;
		if (nums.size())
		{
			int first = nums[0];
			int second = 0x7fffffff;// Max_Int so we can alaways find somethins smaller than it 
			for (int i = 1; i < nums.size()&&!solution; i++)
			{
				if (nums[i]>second)
				{
					solution = true;
				}
				else if (nums[i]>first&&nums[i]<second)
				{
					second = nums[i];
				}
				else if(nums[i]<first)
				{
					first = nums[i];
				}
			}
		}
		return solution;
	}
};


class Solution2 {
public:
	bool increasingTriplet(vector<int> nums) {
		int n1 = 0x7fffffff;
		int n2 = 0x7fffffff;
		for (int n : nums) {
			if (n <= n1) {							//�ж����������ǲ�������   ���������� n1,n2  ��һ���� ��n1С��ֵ��n1
				n1 = n;
			}
			else if (n <= n2) {						//�ڶ������ȵ�һ�����󣬲���ִ�е�����  	��һ���� ��n2С��ֵ��n2
				n2 = n;
			}
			else {										//���������ȵڶ������󣬲���ִ�е����� ����ģ�����true
				return true;
			}
		}

		return false;
	}
};











