#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
//考点：哈希表和数组
/**
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.
Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
 * */
//思路：只扫描 框内的元素，如图只需遍历x上的坐标就阔以了
/**
 * 1 2 3 4 5 6
 * 1 x x x x x
 * 1 x x x x x
 * 1 x x x x x 
 * */
  
bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] != matrix[i - 1][j - 1])
                return false;
        }
    }

    return true;
}
int main()
{
    vector<vector<int>> nums = {{36, 59, 71, 15, 26, 82, 87},
                                {56, 36, 59, 71, 15, 26, 82},
                                {15, 0, 36, 59, 71, 15, 26}};
    std::cout << isToeplitzMatrix(nums) << std::endl;
    system("pause");
    return 0;
}