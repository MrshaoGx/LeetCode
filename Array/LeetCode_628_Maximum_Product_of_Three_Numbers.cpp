#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
 * Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24
Note:
The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

 * 
 * */
//考点：求最大乘积 ，先排序，然后取出数组最大三位数乘积和最小两个数和最后一位乘积，因为可能存在负数
int maximumProduct(vector<int> &nums)
{
    int n=nums.size();
    sort(nums.begin(),nums.end());
    return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[2]);

}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    std::cout <<maximumProduct(nums) << std::endl;
    system("pause");
    return 0;
}