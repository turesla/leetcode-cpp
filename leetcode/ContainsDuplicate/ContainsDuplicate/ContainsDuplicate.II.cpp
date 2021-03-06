/**********************************************************************************
*
* Given an array of integers and an integer k, find out whether there there are
* two distinct indices i and j in the array such that nums[i] = nums[j] and
* the difference between i and j is at most k.
*
*
**********************************************************************************/
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
	bool containsNearbyDuplication(vector<int>&nums, int k)
	{
		unordered_map <int, int>m;
		for (int i = 0; i < nums.size(); i++)
		{
			int n = nums[i];
			if (m.find(n)!=m.end()&&i-m[n]<=k)
			{
				return true;
			}
			m[n] = i;
		}
		return false;
	}
};





