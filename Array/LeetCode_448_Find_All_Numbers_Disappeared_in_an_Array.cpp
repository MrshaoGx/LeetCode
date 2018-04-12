#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
//考点：

/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

 * */
//考点：采用顺序方式把存在数据对应下标全部改为负数，然后查找不是负数的位置则是缺失的数字 Good idea
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n=nums.size();
    for(int i=0;i<n;i++){
        int m=abs(nums[i])-1;
        nums[m]=nums[m]>0?-nums[m]:nums[m];
    }
    return nums;
    vector<int> res;
    for(int i=0;i<n;i++){
        if(nums[i]>0)
            res.push_back(i+1);
    }
    return res;
}
int main()
{
    vector<int> nums = {3,1, 0, 1, 4};
    vector<int> res = findDisappearedNumbers(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    system("pause");
    return 0;
}