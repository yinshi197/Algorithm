#include <iostream>
#include <unordered_set>
 
 
 
int main()
{  
// 简单比较演示
    std::unordered_set<int> example = {1, 2, 3, 4};
 
    auto search = example.find(5);
    if (search != example.end()) {  //end():返回后随下标为 n 的桶的最后元素的元素的迭代器。此元素表现为占位符，试图访问它会导致未定义行为。
        std::cout << "Found " << (*search) << '\n';
    } else {
        std::cout << "Not found\n";
    }
 
 
 
}