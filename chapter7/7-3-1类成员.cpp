#include <iostream>
#include <string>
using namespace std;

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;  //因为Screen有另一个构造函数，所以本函数是必须的
    //cursor被其类被初始化为0

    Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c){}  //cursor成员隐式的使用了类内初始值
    char get() const {return contents[cursor];}  //隐式内联
    inline char get(pos ht,pos wd) const;  //显式内联
    Screen &move(pos r,pos c);  //能在之后被设为内联
    void some_member() const;


private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

    //mutable关键字  可变数据成员，永远不会是const，即使是const对象的成员
    mutable size_t access_ctr;  //在const对象内也能被修改
};

//移动光标
inline
Screen &Screen::move(pos r,pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;  //以左值的形式返回对象
}

//读取给定位置的字符
char Screen::get(pos r,pos c) const  //在内部声明成inline
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const  //这里的const表示this是一个指向常量的指针
{
    ++access_ctr;  //保存一个值，用于记录成员函数被调用的次数
}


int main()
{
    string s1(10,'a');
    cout<<s1<<endl;

    return 0;
}
