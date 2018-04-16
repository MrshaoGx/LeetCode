#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/*Given an array of 2n integers, 
your task is to group these integers into n pairs of integer, 
say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].**/
//考点：排序，非传统快排，效率不是很高
void qsort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    int m = left - 1;
    for (int i = left; i <= right; i++)
        if (nums[i] <= nums[right])
            swap(nums[++m], nums[i]);
    qsort(nums, left, m - 1);
    qsort(nums, m + 1, right);
}
int arrayPairSum(vector<int> &nums)
{

    int sum = 0;
    int n = nums.size();
    qsort(nums, 0, n - 1);
    for (int i = 0; i < n; i += 2)
    {
        sum += nums[i];
    }
    return sum;
}
int main()
{
    vector<int> nums = {7, 3, 1, 0, 0, 6};

    cout << arrayPairSum(nums) << endl;
    system("pause");
    return 0;
}