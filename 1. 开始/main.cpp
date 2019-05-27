//
//  main.cpp
//  DataTypes
//
//  Created by 刘宇轩 on 2019/5/26.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    
    int sum = 0, value = 0;
    //读取文件知道遇到文件尾，计算所有读入的值的和
    while(std::cin >> value){
       // std::cout << "🐮" << std::endl;
        sum += value; // 等价于 sum = sum + value
    }
    std::cout << value << "Sum is: " << sum << std::endl;
    while(std::cin >> value){
        // std::cout << "🐮" << std::endl;
        sum += value; // 等价于 sum = sum + value
    }
    std::cout << value << "Sum is: " << sum << std::endl;
    
    return 0;
}

