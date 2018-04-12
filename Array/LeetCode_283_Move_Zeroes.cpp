#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
 * */
//考点：遍历交换
void moveZeroes(vector<int> &nums)
{
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            int j=i+1;
            while(j<n&&nums[j++]==0);
            swap(nums[i],nums[j-1]);
        }
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> res = twoSum(nums, 6);
    std::cout << res[0] << res[1] << std::endl;
    system("pause");
    return 0;
}