#ifndef EX13_34_36_37_H_INCLUDED
#define EX13_34_36_37_H_INCLUDED
#include <string>
#include <set>
using namespace std;

class Folder;



class Message
{
    friend class Folder;
    friend void swap(Message& lhs,Message& rhs);
public:
    explicit Message(const string &s = "");
    Message(const Message&);
    Message& operator=(const Message&);  //用引用  返回左值
    ~Message();  //删除对象
    //在给定的folder中添加和删除message
    void Save(Folder&);  //因为Folder是动态申请的，传入引用，不拷贝对象
    void Remove(Folder&);  //传入引用，不拷贝对象
public:
    string sContent;  //消息内容
    set<Folder*> pSet_F;
    //将本Message添加到指向参数的Folder中
    void add_to_Folders(const Message&);
    //将message从Folder中删除
    void remove_from_Folders();
};


class Folder
{
    friend class Message;
public:
    Folder(string s = string() );
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void addMsg( Message*);
    //void remMsg(const Message&);  为什么不能用const
    void remMsg( Message*);
public:
    string sName;
    set<Message*> pSet_M;
};


#endif // EX13_34_36_37_H_INCLUDED
