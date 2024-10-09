#include <iostream>

int search_way1(int* array, int length, int target)
{
    int left = 0;
    int right = length;  //左闭右开

    while(left < right)
    {   
        int mid = (left + right) / 2;   //默认向下取整
        if(array[mid] > target)
        {
            right = mid;     //循环条件不包含left == right,为了确保不会错过left == right，right = mid
        }
        else if(array[mid] < target)
        {
            left = mid + 1;
        }
        else 
        {
            return mid;
        }
    }

    return -1;
}

/**
 * @brief 二分查找，适用于闭区间
 * @param 数组，长度， 查找值
 * @return 查找成功返回下标，失败返回插入的下标
 */
int search_way2(int* array, int length, int target)
{
    int left = 0;
    int right = length - 1; //左闭右闭

    while(left <= right)
    {
        int mid = (left + right) / 2;  //默认向下取整
        if(array[mid] > target)
        {
            right = mid -1; //循环包括条件left == right，不会错过
        }
        else if(array[mid] < target)
        {
            left = mid + 1;
        }
        else 
        {
            return mid;
        }
    }

    return left;   //失败后 right = left - 1, left的位置相当原来的right(所有大于插入值中最小的值，那么该位置就是插入位置)
}

int main()
{
    int ret1 = -1;
    int ret2 = -1;
    int array[] = { -1,0,3,5,9,12 };
    for(int i = 0; i < sizeof(array) / sizeof(int); i++)
    // {
    //     ret1 = search_way1(array, sizeof(array) / sizeof(int), array[i]);
    //     ret2 = search_way2(array, sizeof(array) / sizeof(int), array[i]);
    //     std::cout << "ret1 = " << ret1 << " ret2 = "<< ret2 << std::endl;
    // }

    ret2 = search_way2(array, sizeof(array) / sizeof(int), -2);
    std::cout <<"ret2 = "<< ret2 << std::endl;

    return 0;
}