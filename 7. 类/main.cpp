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
    test(){
        
    }
    int intValue;
    double doubleValue;
    std::string stringValue;
};

struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {
        this->units_sold += 10;
        this->units_sold += 10;
        this->units_sold += 10;
        this->units_sold += 10;
        this->units_sold += 10;
        std::cout << bookNo << " <--> " << this->units_sold << std::endl;
    }
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n),revenue(p * n){    }
    Sales_data(std::istream &);
    
    std::string isbn() const {  return bookNo;  }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Sales_data testData("1000");
    std::cout << testData.bookNo << " " << testData.units_sold << std::endl;
    std::cout << "Hello, World!\n";
    return 0;
}
