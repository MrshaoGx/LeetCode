#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Given an array of integers and an integer k,
 *  find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 * */
//考点：同217题，只需要判断下 表中的内容和当前位置差 是否大于等于K
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> map(nums.size());
    for (int i = 0; i< nums.size(); i++)
    {
        if (map.find(nums[i]) != map.end()&&(i-map[nums[i]])<=k)
        {
            return true;
        }
        map[nums[i]]=i;
    }
    return false;
}
int main()
{
    vector<int> nums = {1,2,3,4,1};
    std::cout <<containsNearbyDuplicate(nums, 2) << std::endl;
    system("pause");
    return 0;
}