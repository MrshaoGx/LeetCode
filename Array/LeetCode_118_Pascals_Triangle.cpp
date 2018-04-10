#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/**
 * Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 * */
//考点：二维数组，头尾单独添加，取上一行的数组 进行遍历 赋值给下一行
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res(numRows);
    if (numRows < 1)
        return res;
    vector<int> first(1);
    first[0]=1;
    res[0]=first;
    for (int i = 1; i < numRows; i++)
    {
        vector<int> tmp(i + 1);
        tmp[0] = 1;
        vector<int>::iterator it = res[i - 1].begin();
        int k =1,n=0;
        while (it!=res[i - 1].end())
        {
            tmp[k++] = (*it) + (*(++it));
        }
        tmp[i] = 1;
        res[i]=tmp;
    }
    return res;
}
int main()
{
    vector<vector<int>> res = generate(10);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}