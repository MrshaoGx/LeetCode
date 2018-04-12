#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
/**
 * 
 * Given a non-empty array of integers, 
 * return the third maximum number in this array. 
 * If it does not exist, return the maximum number.
 *  The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
 * */
//考点：set队列，规定队列大小，每次新增时 将最小的元素出队
int thirdMax(vector<int> &nums)
{
    set<int> top3;
    for (int num : nums)
    {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}
int main()
{
    vector<int> nums = {1, 1, 2};
    std::cout << thirdMax(nums) << std::endl;
    system("pause");
    return 0;
}