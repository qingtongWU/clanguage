~~~c
#include <iostream>
using std::cout;
using std::endl;

//1.全局static变量的初始化在程序初始阶段，先于main函数执行
int test1(){
cout << "before main1" << endl;
return 1;
}
static int i = test1();
//2.lambda表达式
int a = []() {
cout << "before main2" << endl;
return 0;
}();

int main() {
cout << "hello world" <<endl;
return 0;
}
//结果如下
before main1
before main2
Hello world
~~~

