#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Given an integer array, 
 * you need to find one continuous subarray that if you only sort this subarray in ascending order,
 *  then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
 * */
//思路：先排序，排完序之后逐个比较，做完之后发现 可以先从左面比，比完之后从右面比
int findUnsortedSubarray(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    vector<int> tmp;
    tmp.assign(nums.begin(), nums.end());
    sort(nums.begin(), nums.end());
    int count = 0;
    int i = 0, j = nums.size() - 1;
    bool stopleft = false, stopright = false;
    while (i < j)
    {
        if (!stopleft && nums[i] == tmp[i])
        {
            count++;
            i++;
        }
        else
            stopleft = true;

        if (!stopright && nums[j] == tmp[j])
        {
            count++;
            j--;
        }
        else
            stopright = true;

        if (stopleft && stopright)
        {
            break;
        }
    }
    if (i == j && nums[i] == tmp[j])
        count++;

    return nums.size() - count;
}
// int findUnsortedSubarray(vector<int> &nums)
// {
//     vector<int> tmp;
//     tmp.assign(nums.begin(), nums.end());
//     sort(nums.begin(), nums.end());
//     int start = -1;
//     int end = -1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == tmp[i])
//         {
//             if (end == -1 && start >= 0)
//                 end = i - 1;
//         }
//         else
//         {
//             end = nums.size() - 1 == i ? i : -1;
//             if (start == -1)stopright
//                 start = i;
//         }
//     }
//     if (start < end)
//     {
//         return end - start + 1;
//     }
//     else if (start > end)
//     {
//         return nums.size();
//     }
//     return 0;
// }

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3};
    std::cout << findUnsortedSubarray(nums) << std::endl;
    system("pause");
    return 0;
}