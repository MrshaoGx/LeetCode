#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
//考点：动态规划，用空间换时间
int maxSubArray(vector<int>& nums) {
    if(nums.size()<=0) return 0;
    int sum=0;
    int subArrays[nums.size()];
    subArrays[0]=nums[0];
    int max=nums[0];
    for(int i=1;i<nums.size();i++){
       subArrays[i]=nums[i] + (subArrays[i - 1] > 0 ? subArrays[i - 1] : 0);  //如果子串之和小于0 则丢弃子串，并从当前位置继续累计
       max=max>subArrays[i]?max:subArrays[i];
    }
    for(int i=0;i<nums.size();i++){
        cout<<subArrays[i]<<" ";
    }
    return max;
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    system("pause");
    return 0;
}