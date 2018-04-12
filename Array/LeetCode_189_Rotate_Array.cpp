#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
 *Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II

*/
//考点：旋转数组指定距离,直接交换对应位置元素到最终位置，并慢慢缩减最大长度，K随着n的变化而变化，直到k等于剩余未交换时的元素，
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n <= 0 || n % k == 0)
        return;
    int m = 0;
    for (; k %= n; n -= k, m += k)
        for (int i = 0; i < k; i++)
        {
            swap(nums[i + m], nums[m + n - k + i]);
        }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 4);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    system("pause");
    return 0;
}