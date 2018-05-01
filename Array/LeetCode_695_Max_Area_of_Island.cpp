#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Given a non-empty 2D array grid of 0's and 1's, 
 * an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
 *  You may assume all four edges of the grid are surrounded by water.u may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
 * */
//考点:回溯，对每个点的四周进行查找，做好记录
int findMore(vector<vector<int>> &grid, vector<vector<bool>> &isVisited, int i, int j)
{
    int num = 0;
    int m = grid.size(), n = grid[i].size();
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 0;
    if (grid[i][j] == 0)
        return 0;
    if (!isVisited[i][j])
    {
        num++;
        isVisited[i][j] = true;
    }
    else
        return 0;
    num += findMore(grid, isVisited, i - 1, j); //top
    num += findMore(grid, isVisited, i, j - 1); //left
    num += findMore(grid, isVisited, i, j + 1); //right
    num += findMore(grid, isVisited, i + 1, j); //down
    return num;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    if (grid.size() <= 0)
    {
        return 0;
    }
    int max = 0;

    int m = grid.size();

    vector<vector<bool>> isVisited(m);
    for (int i = 0; i < m; i++)
    {
        int n = grid[i].size();
        for (int j = 0; j < n; j++)
        {
            isVisited[i].push_back(false);
        }
    }
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < grid[i].size(); j++)
        {
            if (isVisited[i][j] || grid[i][j] == 0)
            {
                isVisited[i][j] = true;
                continue;
            }

            int tmp = findMore(grid, isVisited, i, j);
            max = max > tmp ? max : tmp;
        }
    }
    return max;
}
int main()
{
    vector<vector<int>> nums = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    vector<vector<int>> arr = {{1, 1, 0, 0, 0}, 
                               {1, 1, 0, 0, 0}, 
                               {0, 0, 0, 1, 1}, 
                               {0, 0, 0, 1, 1}};
    std::cout << maxAreaOfIsland(arr) << std::endl;
    system("pause");
    return 0;
}