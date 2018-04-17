#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/*In MATLAB, there is a very useful function called 'reshape',
 which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, 
and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.**/

//考点：遍历一遍旧数组 取出来放到对应新数组中，如果新数组行满 就换行，处理好边界，直到新数组行结束
vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
{
    int h = nums.size();
    int w = 0;
    if (h > 0)
        w = nums[0].size();
    if (w * h != r * c)
    {
        return nums;
    }
    vector<vector<int>> res(r);
    int i = 0, j = 0, o = 0, p = 0;
    while (o < r)
    {
        while (p < c && i < h)
        {
            res[o].push_back(nums[i][j++]);
            p++;
            if (j >= w)
            {
                j = 0;
                i++;
            }
        }
        p=0;
        o++;
    }
    return res;
}
int main()
{
    vector<vector<int>> nums = {{1, 2}, {3, 4}};
    nums = matrixReshape(nums, 4, 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}