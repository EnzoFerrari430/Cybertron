#include <iostream>

/*
    指针和引用的区别
    指针有自己的内存空间，
    引用没有自己的内存空间

    引用绑定后就一直和这个对象绑定到了一起
    而指针就不一样，给指针一个新的值，就指向了一个新的对象



    p是int型指针
    if(p)判断这个指针是否为空
    if(*p)判断这个指针指向的内容是否为0


    练习2.23：给定指针p，你能知道它是否指向了一个合法的对象吗?如果能，叙述判断的思路；如果不能，也请说明原因。
    答：应该不能判断指针p是否指向了一个合法的对象，因为如果指针p没有被初始化，p存放的是一个随机的地址，这是一件极其危险的事情，
    再者，如果p没有被合法的初始化，恶意存放了一个地址，也是危险的。所以，需要程序员自己清楚指针是否被合法使用。
*/

int main()
{
    int i = 100;
    int *p1 = &i;
    int *p2 = &i;

    std::cout<<p1<<std::endl;
    //更改指针的值
    p1 = p1 + 4;
    std::cout<<p1<<std::endl;

    //更改指针所指对象的值
    *p2 = 101;

    std::cout<<*p2<<std::endl;
    std::cout<<i<<std::endl;

    //用指针得出42的平方
    int j = 42;
    int *pi = &j;
    *pi =  *pi * *pi;
    std::cout<<j<<std::endl;

    /*
    int ii = 0;
    //double *dp = &ii;  //指针的类型和指向的对象类型不符
    int *ip = 0;
    //int *ip = ii;  //wrong
    int *p = &ii;
    */

    return 0;
}
