#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.*/
//考点：数组元素遍历，数量最多的元素计数肯定大于0 
int majorityElement(vector<int> &nums)
{
	int major=nums[0],count=1;
	for(int i=1;i<nums.size();i++){
		if(count==0){
			count++;
			major=nums[i];
		}else if(major==nums[i]){
			count++;
		}else
			count--;
	}

	return major;
}
int main()
{
	vector<int> nums(1);
	nums[0]=1;
	cout<<majorityElement(nums)<<endl;
	system("pause");
	return 0;
}