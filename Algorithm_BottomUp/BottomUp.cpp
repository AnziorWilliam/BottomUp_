#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void Merge(vector<int>& Array, int front, int mid, int end)
{
    //Ĭ�����Ҿ�������
    //ȡ���������и�С��ֵ��Ϊԭ������i��ֵ
    //�ݹ�ֱ��ȫ������
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