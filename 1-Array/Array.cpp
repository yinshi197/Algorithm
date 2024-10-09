#include <iostream>

int main()
{
    //1.二维数组的地址,C++中是连续分布的
    int array[2][3]= {
        {1,2,3},
        {4,5,6}
    };
    std::cout << "Array address:\n";
    std::cout << "array[0][0] = " << &array[0][0] << std::endl;
    std::cout << "array[0][1] = " << &array[0][1] << std::endl; 
    std::cout << "array[0][2] = " << &array[0][2] << std::endl;
    std::cout << "array[1][0] = " << &array[1][0] << std::endl;
    std::cout << "array[1][1] = " << &array[1][1] << std::endl;
    std::cout << "array[1][2] = " << &array[1][2] << std::endl;

    return 0;
}