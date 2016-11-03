/**********************************************************************************
*
* Given two strings s and t, write a function to determine if t is an anagram of s.
*
* For example,
* s = "anagram", t = "nagaram", return true.
* s = "rat", t = "car", return false.
*
* Note:
* You may assume the string contains only lowercase alphabets.
*
**********************************************************************************/
#include<string>
#include<algorithm>
using std::string;


class Solution {
public :
	//stupid way - but easy to understand  - 76ms
	bool isAnagram01(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}


	//using a map to count every chars in the string.
	bool isAnagram02(string s, string t)
	{
		int map[26] = { 0 };//only lowercase alphabets
        //memset(map, 0, sizeof(map));
		
		//count each char for s
		for (int i = 0; i < s.size(); i++)
		{
			map[s[i] - 'a']++;
		}

		//decrease the count for t
		for (int i = 0; i < t.size(); i++)
		{
			map[t[i] - 'a']--;
		}

		for (int i = 0; i < sizeof(map) / sizeof(map[0]))
		{
			if (map[i] != 0) return false;
		}
		return true;
	}

	bool isAnagram(string s, string t)
	{
		return isAnagram01(s, t);
		return isAnagram02(s, t);
	}

};





