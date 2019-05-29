//
//  main.cpp
//  2. 变量和基本类型
//
//  Created by 刘宇轩 on 2019/5/27.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>

extern  int bufSize;
int main(int argc, const char * argv[]) {
    bufSize += 10;
    std::cout << bufSize << std::endl;
}
