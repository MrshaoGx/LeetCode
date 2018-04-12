#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 * */
//考点：暴力吧累加之后递减
int missingNumber(vector<int> &nums)
{
    int n=nums.size();
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    for(int i=0;i<n;i++){
        sum-=nums[i];
    }
    return sum;
}
int main()
{
    vector<int> nums = {0, 1, 3, 4, 5};
    std::cout << missingNumber(nums)<< std::endl;
    system("pause");
    return 0;
}