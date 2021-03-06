/**********************************************************************************
*
* The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
* The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned
* in the top-left room and must fight his way through the dungeon to rescue the princess.
*
* The knight has an initial health point represented by a positive integer.
* If at any point his health point drops to 0 or below, he dies immediately.
*
* Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
* other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
* In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
*
* Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
* For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path
* RIGHT-> RIGHT -> DOWN -> DOWN.
*
*
*   +------+------+------+
*   |      |      |      |
*   | -2(K)|  -3  |  -3  |
*   |      |      |      |
*   +--------------------+
*   |      |      |      |
*   |  -5  | -10  |   1  |
*   |      |      |      |
*   +--------------------+
*   |      |      |      |
*   |  10  |  30  | -5(P)|
*   |      |      |      |
*   +------+------+------+
*
*
* Notes:
*
* The knight's health has no upper bound.
* Any room can contain threats or power-ups,
* even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*
* Credits:Special thanks to @stellari for adding this problem and creating all test cases.
*
**********************************************************************************/
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int calculateMininumHP(vector<vector<int>>&dungeon)
	{
		int row = dungeon.size();
		int col = row > 0 ? dungeon[0].size() : 0;
		if (row <= 0 || col <= 0)
		{
			return 0;
		}
		//vector<vector<int>> a(row, vector<int>(col));  ��̬����

		//dp[r][c] = min(max(dp[r+1][c]-dungeon[r][c],1), max( dp[r][c+1] - dungeon[r][c], 1));
		int **dp;
		dp = new int *[row];
		for (int i = 0; i < row; i++)
		{
			dp[i] = new int[col];
		}
		memset(dp, 0, sizeof(dp));

		for (int r = row - 1; r >= 0; r--)
		{
			for (int c = col - 1; c >= 0; c--)
			{
				/*if (r == row - 1 && c == col - 1 ){
				dp[r][c] = max(1 - dungeon[r][c], 1);
				}else if ( r == row - 1 ) {
				dp[r][c] = max(dp[r][c+1] - dungeon[r][c], 1);
				}else if ( c == col - 1 ) {
				dp[r][c] = max(dp[r+1][c] - dungeon[r][c], 1);
				}else{
				dp[r][c] = min( max( dp[r+1][c] - dungeon[r][c], 1), max( dp[r][c+1] - dungeon[r][c], 1) );
				}*/
				if (r == row - 1 && c == col - 1)
				{
					dp[r][c] = max(1 - dungeon[r][c], 1);
				}
				else
				{
					int h1 = (c == col - 1) ? INT_MAX : max(dp[r][c + 1] - dungeon[r][c], 1);
					int h2 = (r == row - 1) ? INT_MAX : max(dp[r + 1][c] - dungeon[r][c], 1);

					dp[r][c] = min(h1, h2);
				}
			}
		}
		return dp[0][0];
	}
};




int main()
{

}







