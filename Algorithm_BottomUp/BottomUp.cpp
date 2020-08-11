#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void Merge(vector<int>& Array, int front, int mid, int end)
{
    //默认左右均已有序
    //取左右子树中更小的值作为原数列中i的值
    //递归直至全部有序
    vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
    vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());
    for (int i = front; i <= end; i++)
    {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight])
        {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}
void MergeSort(vector<int>& Array, int front, int end)
{
    if (front >= end)
    {
        return;
    }
    int mid = (front + end) / 2;
    MergeSort(Array, front, mid);
    MergeSort(Array, mid + 1, end);
    Merge(Array, front, mid, end);
}
int main()
{
    srand(time(0));
    vector<int>my_v;
    for (int i = 0; i < 10; i++)
    {
        my_v.push_back(rand() % 10);
    }
    cout << "original_list" << endl;
    for (auto it = my_v.begin(); it != my_v.end(); it++)
    {
        cout << *it << endl;
    }
    MergeSort(my_v, 0, my_v.size() - 1);
    cout << "after_sort" << endl;
    for (auto it = my_v.begin(); it != my_v.end(); it++)
    {
        cout << *it << endl;
    }
}