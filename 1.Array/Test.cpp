#include <iostream>
#include <vector>

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

std::vector<int> test(int* array, int length, int target)
{
    int index = search_way2(array, length, target);
    int left = index;
    int right = index;
    if(index == -1)
    {
        return {-1, -1};
    }

    while(array[left - 1] == array[index] && left - 1 > 0)
    {
        left--;
    }
    while(array[right + 1] == array[index] && right + 1 < length -1 )
    {
        right++;
    }
    return {left, right};
}

int main()
{
    int array[] = { -1,0,5,5,5,6 };
    std::vector<int> a = test(array, 6, 5);
    std::cout << a[0] << " " << a[1] << std::endl; 
    return 0;
}