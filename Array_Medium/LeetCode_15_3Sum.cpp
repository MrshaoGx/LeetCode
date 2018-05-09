#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 * */
//思路：双指针，先排序，再遍历此数组，将其中n-2元素作为基准位，头指针为基准位右侧第一个，尾指针为数组末尾，直到指针相遇。
vector<vector<int>> threeSum(vector<int> &nums)
{
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;
	for(int i=0;i<nums.size();i++){
		if(i>0&&nums[i]==nums[i-1])
			continue;
		int left=i+1,right=nums.size()-1;
		while(left<right){
			int s=nums[i]+nums[left]+nums[right];
			if(s>0){
				right--;
			}else if(s<0)
				left++;
			else
			{
				res.push_back(std::vector<int>{nums[i],nums[left],nums[right]});
				while(nums[left]==nums[left+1])
					left++;
				while(nums[right]==nums[right-1]){
					right--;
				}
				left++;
				right--;
			}
		}
	}
	return res;
}
int main()
{
    vector<int> nums={-1,0,1,2,-1,2,3};
    threeSum(nums);
    return 0;
}