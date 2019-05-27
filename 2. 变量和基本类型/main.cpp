//
//  main.cpp
//  2. 变量和基本类型
//
//  Created by 刘宇轩 on 2019/5/27.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl; // 输出-84
    std::cout << u + i << std::endl; // 如果int占32位，输出4294967264
    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl; // 输出 32
    std::cout << u2 - u1 << std::endl; // 输出取模后的
    return 0;
}
