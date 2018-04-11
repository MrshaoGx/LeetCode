#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
//考点：查找算法,有序数组查找果断 二分法
 vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        for(int i=0;i<numbers.size();i++){
            res[0]=i+1;
            int left=i+1,right=numbers.size()-1;
            int p=target-numbers[i];
            while(left<=right){
                int mid=(left+right)/2;
                if(numbers[mid]==p)
                {
                    res[1]=mid+1;
                    return res;
                }else if(numbers[mid]>p){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            } 
        }
        return res;
 }
int main()
{
	vector<int> nums = {-1,7,10,15};
	vector<int> res = twoSum(nums, 9);
	std::cout << res[0] << res[1] << std::endl;
	system("pause");
	return 0;
}