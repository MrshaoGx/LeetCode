#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * 
 * Given a 2D integer matrix M representing the gray scale of an image, 
 * you need to design a smoother to make the gray scale of 
 * each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. 
 * If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].

 * */
//没看懂这题啥意思，评论区抄了一份过来的  标个标记吧 ⭐⭐⭐
// 2019-04-19 留：腐蚀和膨胀。。Manhattan距离。。原来如此
vector<vector<int>> imageSmoother(vector<vector<int>> &M)
{
    if (M.empty())
        return vector<vector<int>>();
    vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));
    vector<pair<int, int>> dir({{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}});
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[0].size(); j++)
        {
            int nume = 0, deno = 0;
            for (const auto &d : dir)
            {
                int ii = i + d.first, jj = j + d.second;
                if (ii >= 0 && ii < M.size() && jj >= 0 && jj < M[0].size())
                {
                    deno++;
                    nume += M[ii][jj];
                }
            }
            result[i][j] = nume / deno;
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> nums = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    imageSmoother(nums);
    system("pause");
    return 0;
}
