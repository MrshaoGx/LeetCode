#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Given an array and a value, 
 * remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, 
 * you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. 
 * It doesn't matter what you leave beyond the new length.
 * */
//考点：思路-》排序-》遍历
int removeElement(vector<int>& nums, int val) {
    if(nums.size()<=0) return 0;
    sort(nums.begin(),nums.end());
    int k=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==val)
            continue;
        nums[k++]=nums[i];
    }
    return k;
}
int main()
{
      vector<int> nums = {3, 2, 2,3};
    int res = removeElement(nums,3);
    cout << res << endl;
    for (int i = 0; i < res; i++)
    {
        cout << nums[i] << " ";
    }
    system("pause");
    return 0;
}