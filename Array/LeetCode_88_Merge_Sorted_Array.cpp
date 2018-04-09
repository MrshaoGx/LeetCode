#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
 * */
//考点：合并数组，倒着插入到数组A中，直到将B中的完全取出则结束，剩余A自然有序
void merge(vector<int> &A, int m, vector<int> &B, int n)
{
   int p = m-1, q = n-1, i = m+n-1;   
        while ( q>=0 ) {
            if ( p<0 || B[q] >= A[p] )
                A[i--] = B[q--];
            else
                A[i--] = A[p--]; 
        }
}
int main()
{

    vector<int> nums1 = {1,2,3,4,1,1,1,1};
    vector<int> nums2 = {1,2,3,5,5,5,5,4};
    merge(nums1,4,nums2,4);
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
    system("pause");
    return 0;
}