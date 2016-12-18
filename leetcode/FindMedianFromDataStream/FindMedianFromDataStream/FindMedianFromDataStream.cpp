/***************************************************************************************
*
* Median is the middle value in an ordered integer list. If the size of the list is
* even, there is no middle value. So the median is the mean of the two middle value.
* Examples:
* [2,3,4] , the median is 3
* [2,3], the median is (2 + 3) / 2 = 2.5
*
* Design a data structure that supports the following two operations:
*
* void addNum(int num) - Add a integer number from the data stream to the data
* structure.
* double findMedian() - Return the median of all elements so far.
*
* For example:
*
* add(1)
* add(2)
* findMedian() -> 1.5
* add(3)
* findMedian() -> 2
***************************************************************************************/

//找中间的值，用set 容器 指针 平衡两个set 之间的数量 然后求第一个set 最后一个元素和第二个set 第一个元素的平均值

#include<set>
using namespace std;

class MedianFinder {
private :
	//we seprate the sorted array to two parts 
	multiset<int>first, second;


public:
	//Adds a number into the data structure;
	void addNum(int num)
	{
		if (first.empty()||num<=*(first.rbegin()))
		{
			first.insert(num);
		}
		else
		{
			second.insert(num);
		}

		if (first.size()>second.size()+1)
		{
			auto it = first.end();
			it--;
			second.insert(*(it));
			first.erase(it);
		}
		if (first.size()<second.size())
		{
			first.insert(*(second.begin()));
			second.erase(second.begin());
		}
	}


	double findMedian() {
		if (first.size()>second.size())
		{
			return *(first.rbegin);
		}
		double x = *first.rbegin();
		double y = *second.begin();
		return (x + y) / 2;
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();