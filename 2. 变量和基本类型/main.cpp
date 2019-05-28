//
//  main.cpp
//  2. 变量和基本类型
//
//  Created by 刘宇轩 on 2019/5/27.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    int ival = 1024;
    int& refVal = ival;
    
    std::cout << typeid(refVal).name() << " " << typeid(ival).name() << std::endl;
}
