//
//  main.cpp
//  2. 变量和基本类型
//
//  Created by 刘宇轩 on 2019/5/27.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    int i = 1024, i2 = 2048;
    int &r = i;
    int &r2(i2);
    
    std::cout << r2 << std::endl;
    
}
