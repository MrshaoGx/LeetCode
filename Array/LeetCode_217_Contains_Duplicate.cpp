#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 
 * Given an array of integers, find if the array contains any duplicates.
 * 
 *  Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
 * */
//考点：查重用map就好了
bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map(nums.size());
    for (int i = 0; i< nums.size(); i++)
    {
        if (map.find(nums[i]) != map.end())
        {
            return true;
        }
        map[nums[i]]=i;
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 1, 3, 4, 5};
    std::cout << containsDuplicate(nums) << std::endl;
    system("pause");
    return 0;
}