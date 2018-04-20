#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
 * 
 * */
// 考点：顺序比大小，一旦超过1就立即返回
bool checkPossibility(vector<int> &nums)
{
    bool m = false;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            if (m++)
                return false;
            (i - 2 < 0 || nums[i - 2] <= nums[i]) ? nums[i - 1] = nums[i] : nums[i] = nums[i - 1]; //重点：根据当前位置和比较情况，修改原数组的值
        }
    }
    return true;
}
int main()
{
    vector<int> nums = {4, 2, 3};
    std::cout << checkPossibility(nums) << std::endl;
    system("pause");
    return 0;
}