#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
/**
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
 * 
 **/
//考点：进位运算 只判断最后一位如果是9 最后一位则置0，到倒数第二位时进位并返回
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }
    digits[0] = 1;  //如果循环结束 证明第一位是9 进行进位操作
    digits.push_back(0);
    return digits;
}

int main()
{

    vector<int> nums = {9};
    nums = plusOne(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << +" ";
    }
    system("pause");
    return 0;
}