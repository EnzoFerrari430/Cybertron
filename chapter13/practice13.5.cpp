class HasPtr
{
public:
    HasPtr(const std::string &s = std::string() ):ps(new std::string(s)),i(0){}



private:
    std::string *ps;
    int i;
};
HasPtr::HasPtr(const HasPtr &hp)
{
    //ps = new std::string();
    //ps = *hp.ps;

    ps = new std::string( *hp.ps );  //拷贝ps指向的对象，而不是拷贝指针本身
    i = hp.i;

}
