#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/**
 * Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].
 * */
//考点：
vector<int> getRow(int rowIndex)
{
     vector<int> res(rowIndex+1);
      res[0] = 1;
    if(rowIndex<=0) return res;
    int key = rowIndex;
    for (int i = 0; i <=rowIndex; i++)
    {
        for (int j = i; j > 0; --j)
        {
            res[j] = res[j] + res[j - 1];
        }
    }
    return res;
}
int main()
{
    vector<int> res = getRow(5);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i]<<" ";
    }
    system("pause");
    return 0;
}