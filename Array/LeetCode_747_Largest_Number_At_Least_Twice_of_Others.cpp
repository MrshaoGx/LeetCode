#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
 

Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
 

Note:

nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].
 * 
 * */
//考点：记录最后两个数的下标
int dominantIndex(vector<int> &nums)
{
    int max1 = 0, max2 = 0, idxOfMax1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > max1)
        {
            max2 = max1;
            max1 = nums[i];
            idxOfMax1 = i;
        }
        else if (nums[i] > max2)
        {
            max2 = nums[i];
        }
    }
    return max1 >= max2 * 2 ? idxOfMax1 : -1;
}
int main()
{
    vector<int> nums = {1, 6, 3, 2,2};
    std::cout << dominantIndex(nums) << std::endl;
    system("pause");
    return 0;
}