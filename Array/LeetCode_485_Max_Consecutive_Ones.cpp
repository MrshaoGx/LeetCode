#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 * 
 * */

//考点：O(n)时间复杂度，遍历遇0清空，记录最大的长度
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max=0;
    int res=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]!=0)
            max++;
        else{
            res=max>res?max:res;
            max=0;
        }
    }
    res=max>res?max:res;
    return res;
}
int main()
{
    vector<int> nums = {1};
    std::cout <<findMaxConsecutiveOnes(nums)<< std::endl;
    system("pause");
    return 0;
}