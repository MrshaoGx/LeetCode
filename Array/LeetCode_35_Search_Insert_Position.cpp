#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/**
 * Given a sorted array and a target value, 
 * return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0
 * 
 * 
 * */
//考点：二分查找
int BinarySerach(vector<int> &nums,int target){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int middle=(low+high)/2;
        if(nums[middle]<target){
            low=middle+1;
        }else{
            high=middle-1;
        }
    }
    return low;
}
int searchInsert(vector<int> &nums,int target)
{   
    return BinarySerach(nums,target);
}
int main()
{
    vector<int> nums={1,3,5,6};
    cout<<searchInsert(nums,7)<<endl;
    system("pause");
    return 0;
}