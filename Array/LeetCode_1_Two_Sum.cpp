#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
//考点：哈希表和数组
vector<int> twoSum(vector<int> &nums, int target)
{
	unordered_map<int,int> hash;
	vector<int> res;
	for(int i=0;i<nums.size();i++){
		int t=target-nums[i];
		if(hash.find(t)!=hash.end()){
			res.push_back(hash[t]);
			res.push_back(i);
			return res;
		}
		hash[nums[i]]=i;
	}
	return res;
}
int main()
{
	vector<int> nums = {1, 2, 3, 4, 5};
	vector<int> res = twoSum(nums, 6);
	std::cout << res[0] << res[1] << std::endl;
	system("pause");
	return 0;
}