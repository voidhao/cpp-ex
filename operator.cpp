#include <iostream>
#include <string>
#include <map>

class Tank {
    //输出运算符重载，这里只能使用友元函数进行重载，因为输出运算符重载中第一个参数必须是一个ostream对象。
    friend std::ostream &operator<<(std::ostream &out, Tank &t); 
    public:
        Tank(std::string code = "", int num = 0);
        ~Tank() {cnt_--;}
        Tank operator+(Tank &k);
        Tank &operator-();
        Tank &operator++(); //前置++运算符重载
        void print_info();
        static void print_cnt();
    private:
        std::string m_sCode;
        int num_;
        static int cnt_;
};

int Tank::cnt_ = 0;

void Tank::print_cnt() {
    std::cout << "cnt = " << cnt_ << std::endl;
}

std::ostream &operator<<(std::ostream &out, Tank &t) {
    out << "code:" << t.m_sCode << " num:" << t.num_ << std::endl;
    return out;
}

Tank &Tank::operator++() {
    this->num_++;
    return *this;
}

Tank::Tank(std::string code, int num) : m_sCode(code), num_(num) {
    cnt_++;
}

Tank Tank::operator+(Tank &k) {
    Tank temp;
    temp.m_sCode = m_sCode + k.m_sCode;
    temp.num_ = num_ + k.num_;
    return temp;
}

Tank &Tank::operator-() {
    num_ = -num_;    
    return *this;
}

void Tank::print_info() {
    std::cout << "code: " << m_sCode << " num: " << num_ << std::endl;
}

int main()
{
    Tank t1;
    t1.print_info();
    Tank t2("001", 1);
    Tank t3 = t1 + t2; //这里=运算符被默认重载了，就是拷贝赋值
    std::cout << t3;
    ++t3;
    std::cout << t3;
    Tank::print_cnt();
    
    return 0;
}
