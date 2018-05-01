#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
 * */
//考点：动态规划，倒序遍历所有数据，递减存入数组，判断气势点和第二点的数据大小为最终结果。
int minCostClimbingStairs(vector<int> &cost)
{
    for(int i=cost.size()-3;i>=0;i--)
    {
        cost[i]=cost[i]+(cost[i+1]<cost[i+2]?cost[i+1]:cost[i+2]);
        cout<<cost[i]<<endl;
    }
    return cost[0]<cost[1]?cost[0]:cost[1];
}
int main()
{
    vector<int> nums = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << minCostClimbingStairs(nums) << std::endl;
    system("pause");
    return 0;
}