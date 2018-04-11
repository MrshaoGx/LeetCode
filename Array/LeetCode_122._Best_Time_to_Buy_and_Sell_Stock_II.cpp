#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
 You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
 However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * */
//考点：把前面小和后面大的区间之和累加一下就好了
int maxProfit(vector<int> &prices)
{
	int maxPro=0;
	int len=prices.size()-1;
	for(int i=0;i<len;i++){
		if(prices[i]<prices[i+1]){
			maxPro+=prices[i+1]-prices[i];
		}
	}
	return maxPro;
}

int main()
{
	vector<int> nums = {};
	std::cout << maxProfit(nums) << std::endl;
	system("pause");
	return 0;
}