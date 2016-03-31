#include <iostream>
#include <string>
#include <typeinfo>
#include <memory>
using namespace std;

//接口类
class canFly {
    public:
        virtual void takeoff() = 0;
        virtual void land() = 0;
};

class plane : public canFly {
    public:
        plane(string num) : num_(num) {cout << "plane()" << endl;}
        ~plane() {cout << "~plane()" << endl;}
        virtual void takeoff(); 
        virtual void land();
        void carry();
    private:
        string num_;
};

class bird : public canFly {
    public:
        bird(string name) : name_(name) {cout << "bird()" << endl;}
        ~bird() {cout << "~bird()" << endl;}
        virtual void takeoff();
        virtual void land();
        void eat();
    private:
        string name_;
};
void plane::carry() {
    cout << "plane carry" << endl;
}

void bird::eat() {
    cout << "bird eat" << endl;
}

void plane::takeoff() {
    cout << "plane takeoff" << endl;
}
void plane::land() {
    cout << "plane land" << endl;
}

void bird::takeoff() {
    cout << "bird takeoff" << endl;
}
void bird::land() {
    cout << "bird land" << endl;
}

//RTTI，运行时类型识别
void flyMatch(canFly *craft) {
    craft->takeoff();
    if (typeid(*craft) == typeid(plane))
    {
        plane *p = dynamic_cast<plane *>(craft);
        p->carry();
    }
    else if (typeid(*craft) == typeid(bird))
    {
        bird *b = dynamic_cast<bird *>(craft);
        b->eat();
    }
}

int main()
{
    plane *p = new plane("001"); //这里可以传入从堆中申请的对象的指针，也可以直接传递从栈中申请对象的地址，其实两者都一样，传递的都是地址。
    bird *b = new bird("mike");

    flyMatch(p);
    flyMatch(b);
    cout << "-----------" << endl;
    int a = 4;
    auto pa = make_shared<int>(a);
    shared_ptr<int> pb;
    pa = pb;
    cout << *pa << endl;

    return 0;
}
