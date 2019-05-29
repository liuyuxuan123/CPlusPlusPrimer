# 类
&emsp;类的基本思想`数据抽象(data abstraction)`和 `封装(encapsulation)`。数据抽象是一种依赖于`接口(interface)`和`实现(implementation)`分离的编程技术。

&emsp;类想实现数据抽象和封装，需要首先定义一个`抽象数据类型(abstract data type)`。**`在抽象数据类型中，由类的设计者负责考虑类的实现过程：使用该类的程序员只需要抽象的思考类型做了什么，而无需了解类型的工作细节。`**
## 定义抽象数据类型
`WARNING: `   **`定义在类内部的函数是隐式的inline函数`**
&emsp;将函数定义为`内联函数(inline)`，通常就是在它每个调用节点"内联地"展开，一般来说，`内联机制适用于优化规模较小，流程直接，频繁调用的函数`。则如下调用：
```
    std::cout << shorterString(s1, s2) << std::endl;
```
&emsp;在编译过程中展开成类似下面的调用`(但是要注意，内联说明只是向编译器发出的一个请求，编译器可以选择忽略这个请求)`。
```
    std::cout << (s1.size() <  s2.size() ? s1 : s2) << std::endl;
```
### `const成员函数`
&emsp;`const`的作用是修改隐式`this`指针的类型。默认情况下，`this`指针的类型是指向类类型非常量版本的常量指针。例如在`Sales_data`成员函数中，`this`的类型是`Sales_data* const` 。尽管`this`是隐式的，但它仍然需要遵循初始化规则，意味着(在默认情况下)我们不能把`this`绑定到一个常量对象上。这一情况使得我们不能在一个常量对象上调用普通的成员函数。 除非`this指针`可以被定义为`const Sales_data* const`。如果一个函数不会改变`this`所指向的对象，我们可以把`this指针设置为指向常量的指针，这样还有助于提高函数的灵活性。` 然而，`this指针`是隐式的并且不会出现在参数列表当中，所有在哪里将`this指针`声明成指向常量的指针就成为我们必须面对的问题。`C++语言`的做法是允许把`const关键字`放在成员函数的参数列表之后，此时，紧跟在参数列表后面的`const`表示`this指针`是一个指向常量的指针。像这样使用`const`的成员函数被称为`常量成员函数(const member funciton)`。
```
    std::string isbn() const {  return this->bookNo;    }
```
`WARNING：` 常量对象，以及常量对象的引用或者指针都只能调用常量成员函数。
### 类作用域和成员函数
&emsp;`类本身就是一个作用域，类的成员函数的定义嵌套在类的作用域之内。`值得注意的是， 即使`bookNo`定义在`isbn`之后，`isbn`还是可以使用 `bookNo`。 编译器分`两步`处理类: 首先编译成员的声明，然后才轮到成员函数体(如果有的话)。因此，成员函数体可以随意使用类中的其他成员而无需在意这些成员的出现顺序。
### 定义一个返回`this`对象的函数
```
Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```
&emsp;`combine函数`设计的初衷类似于`复合赋值运算符+=`。一般来说，当我们定义的函数类似于某个内置运算符时，应该令该函数的行为尽量模仿这个运算符。内置的赋值运算符把它的左侧运算对象当作左值返回。
### 定义类相关的非成员函数
&emsp;类的作者常常需要一些辅助函数， 比如`add`,`read`和`print`等。尽管这些函数定义的操作从概念上来说输入`类的接口的组成部分`，但它们实际上不属于类本身。我们定义非成员函数的方式与定义其他函数一样，通常把函数的声明和定义分开来。如果函数在概念上属于类但是不定义在类中，则`它一般应与类声明(而非定义)在同一个文件中`。在这种情况下，用户使用接口的任何部分都只需要引入一个文件。

```
istream &read(istream &is, Sales_data &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
``` 
&emsp;`read函数`从给定流中将数据读到给定对象里， `print函数`函数负责将给定对象的内容打印到给定流中。 值得注意的是， 第一点，`read`和`print`分别接受一个格子`IO类型`的引用作为参数，这是因为`IO类`属于不能被拷贝的类型，因此我们只能通过引用来传递它们。而且因为读取和写入操作会改变流中的内容，所以两个函数接受的都是普通引用，而非常量的引用。第二点， `print函数`不负责换行，一般来说，执行输出任务的函数应该尽量减少对格式的控制，遮掩够可以确保由用户代码来决定是否换行。

```
Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return lhs;
}
```

### 构造函数


## 访问控制与封装
## 类的其他特性
## 类的作用域
## 构造函数再探
## 类的静态成员
