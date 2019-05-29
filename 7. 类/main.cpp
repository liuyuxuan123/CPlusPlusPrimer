//
//  main.cpp
//  7. 类
//
//  Created by 刘宇轩 on 2019/5/29.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>


class test {
public:
    std::string s1(){
        return s2();
    }
    
    std::string s2(){
        return "Test String 🐮";
    }
    
    std::string s3 = "XXX";
};

int main(int argc, const char * argv[]) {
    // insert code here...
    test atest;
    std::cout << atest.s1() << std::endl;
    std::cout << "Hello, World!\n";
    return 0;
}
