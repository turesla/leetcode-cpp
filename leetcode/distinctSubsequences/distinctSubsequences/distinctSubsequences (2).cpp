/**********************************************************************************
*
* Given a string S and a string T, count the number of distinct subsequences of T in S.
*
* A subsequence of a string is a new string which is formed from the original string
* by deleting some (can be none) of the characters without disturbing the relative positions
* of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*
* Here is an example:
* S = "rabbbit", T = "rabbit"
*
* Return 3.
*
*
**********************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;



//=====================
// Dynamic Programming
//=====================
//
//  The idea as below:
//
//     Considering m[i][j] means the distance from T[i] to S[j], and add the empty "" case, then,
//
//     A) Initialization for empty case:  m[0][j] = 1;
//
//     B) Calculation 
//
//        a) Target-len > Source-len cannot found any substring
//           i > j : m[i][j] = 0;   
//
//        b) if not equal, take the value of T[i] => S[j-1] (e.g. ["ra" => "rabb"] =["ra" => "rab"] )
//           S[j] != T[i] :  m[i][j] = m[i][j-1]
//
//        c) if equal. (e.g.  ["rab" => "rabb"] = ["rab" =>"rab"] + ["ra" => "rab"] ) 
//           S[j] == T[i] :  m[i][j] = m[i][j-1] + m[i-1][j-1]
//
//  1) Initialize a table as below   
//       ""  r  a  b  b  b  i  t
//    ""  1  1  1  1  1  1  1  1
//    r     
//    b   
//    t  
//
//  2) Calculation
//       ""  r  a  b  b  b  i  t
//    ""  1  1  1  1  1  1  1  1
//    r   0  1  1  1  1  1  1  1 
//    b   0  0  0  1  2  3  3  3
//    t   0  0  0  0  0  0  0  3
//

int numDistinct1(string s, string t) {
	vector<vector<int>>m(t.size() + 1, vector<int>(s.size() + 1));

	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{

			if (i==0)
			{
				m[i][j] = 1;
				continue;
			}
			if (i>j)
			{
				m[i][j] = 0;
				continue;
			}
			if (s[j-1]==t[i-1])
			{
				m[i][j] = m[i][j - 1] + m[i - 1][j - 1];
			}
			else
			{
				m[i][j] = m[i][j - 1];
			}
		}
	}

	return m[t.size()][s.size()];
}


//=====================
// Dynamic Programming
//=====================
//
//  The idea here is an optimization of above idea 
//  (It might be difficult to understand if you don't understand the above idea)
//
//    For example:
//
//      S = "abbbc"  T="abb"
//      posMap = { [a]={0}, [b]={2,1} } <- the map of T's every char.
//      numOfSubSeq = {1, 0, 0, 0 }
//
//      S[0] is 'a', pos is 0,  numOfSubSeq = {1, 0+1, 0, 0};
//
//      S[1] is 'b', pos is 2,  numOfSubSeq = {1, 1, 0, 0+0};
//                   pos is 1,  numOfSubSeq = {1, 1, 0+1, 0};
//
//      S[2] is 'b', pos is 2,  numOfSubSeq = {1, 1, 1, 0+1};
//                   pos is 1,  numOfSubSeq = {1, 1, 1+1, 1};
//
//      S[3] is 'b', pos is 2,  numOfSubSeq = {1, 1, 2, 2+1};
//                   pos is 1,  numOfSubSeq = {1, 1, 1+2, 3};
//
//      S[4] is 'c', not found, numOfSubSeq = {1, 1, 3, 3};
// 
//


int numDistinct2(string s, string t)
{
	map<char, vector<int>>pos_map;
	int len = t.size();
	vector<int> numOfSubSeq(len + 1);
	numOfSubSeq[0] = 1;

	for (int i=len-1;i>=0;i--)
	{
		pos_map[t[i]].push_back(i);
	}

	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (pos_map.find(ch)!=pos_map.end())
		{
			for (int j = 0; j < pos_map[ch].size(); j++)
			{
				int pos = pos_map[ch][j];
				numOfSubSeq[pos + 1] += numOfSubSeq[pos];
			}
		}
	}

	return numOfSubSeq[len];
}

//random invoker 
int numDistinct(string s, string t)
{
	srand(time(0));
	if (rand()%2)
	{
		cout << "------Dynamic Programming Method One----" << endl;
		return numDistinct1(s, t);
	}

	cout << "---Dynamic Programming Method Two ---" << endl;
	return numDistinct2(s, t);
}


int main( int argc ,char **argv ) {

	string s = "rabbbit";
	string t = "rabbit";
	if (argc>2)
	{
		s = argv[1];
		t = argv[2];
	}
	cout << "s=\"" << s << "\" t=\"" << t << "\"" << endl;
	cout << "numDistinct = " << numDistinct(s, t) << endl;
	return 0;
}





