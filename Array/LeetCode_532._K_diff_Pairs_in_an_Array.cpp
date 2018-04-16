#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 
 * Given an array of integers and an integer k, 
 * you need to find the number of unique k-diff pairs in the array.
 *  Here a k-diff pair is defined as an integer pair (i, j), 
 * where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Note:
The pairs (i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range: [-1e7, 1e7].

 * */
//考点：hash表，将所有数字存入hash表 对应的value进行累加（遍历到重复的key值时 value值会进行+1）
    //2.遍历hash表，根据k的大小进行判断是否存在该（key+k） 的和。
int findPairs(vector<int> &nums, int k)
{
    int res = 0, n = nums.size();
    unordered_map<int, int> m;
    for (int num : nums)
        ++m[num];
    for (auto a : m)
    {
        if (k == 0 && a.second > 1)
            ++res;
        if (k > 0 && m.count(a.first + k))
            ++res;
    }
    return res;
}
int main()
{
    system("pause");
    return 0;
}