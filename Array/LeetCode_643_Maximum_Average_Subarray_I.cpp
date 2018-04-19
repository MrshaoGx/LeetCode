#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/*

Given an array consisting of n integers, 
find the contiguous subarray of given length k that has the maximum average value.
 And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/
//考点：找最大区间和
double findMaxAverage(vector<int> &nums, int k)
{
    int maxsum = -2147364847;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i >= k) {
                sum -= nums[i - k];
            }
             if (i >= k - 1) {
                maxsum = max(maxsum, sum);            
            }
        }
        return (double)maxsum / k;
}
int main()
{
    vector<int> nums = {8535, -7482, -9148, 4029, 4086,
                        -2863, -761, -1968, -9685, -6176,
                        -1254, 2445, 1039, 2321, 917,
                        -2641, -8077, 6421, 7040, 5340,
                        4639, 5261, -7277, 4932, 4253,
                        -5315, 1561, -5930, -6204, -3061,
                        401, 7519, -9094, 7907, 847,
                        5083, 6096, -9552, 6772, 7985,
                        -444, -2886, 6317, 4966, -6980};
    std::cout << findMaxAverage(nums, 45) << std::endl;
    system("pause");
    return 0;
}