#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
	vector<int> nums = {1, 2, 3, 4, 5};
	vector<int> res = twoSum(nums, 6);
	std::cout << res[0] << res[1] << std::endl;
	system("pause");
	return 0;
}