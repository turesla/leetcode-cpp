/**********************************************************************************
*
* Compare two version numbers version1 and version1.
* If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
*
* You may assume that the version strings are non-empty and contain only digits and the . character.
* The . character does not represent a decimal point and is used to separate number sequences.
* For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
*
* Here is an example of version numbers ordering:
* 0.1 < 1.1 < 1.2 < 13.37
*
* Credits:Special thanks to @ts for adding this problem and creating all test cases.
*
**********************************************************************************/

#include<vector>
#include<sstream>
using namespace std;



class Solution {
public:
	vector<int>&spilt(const string &s, char delim, vector<int>&elems) {
		stringstream ss(s);
		string item;
		while (getline(ss,item,delim))
		{
			elems.push_back(atoi(item.c_str()));
		}
	}

};









