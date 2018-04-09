#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Given a sorted array,
 * remove the duplicates in-place such that each element 
 * appear only once and return the new length.
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * Example:
 * Given nums = [1,1,2],
 * Your function should return length = 2,
 * with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 * */
//考点：数组遍历，相邻比较
int removeDuplicates(vector<int> &nums)
{
     if(nums.size()<=0) return 0;
    int k = 0;
    for (int i =1; i < nums.size(); i++)
    {
        if(nums[k]!=nums[i])
        {
            nums[++k]=nums[i];
        }
       
    }
    return k+1;
}
int main()
{
    vector<int> nums = {1, 1, 2,3};
    int res = removeDuplicates(nums);
    cout << res << endl;
    for (int i = 0; i < res; i++)
    {
        cout << nums[i] << " ";
    }
    system("pause");
    return 0;
}