#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Student {
    public: 
        Student(string name = "", string sex = "");
        Student(int score);

        ~Student() {
            delete []p;
            cout << "delete " << endl; 
        }

        Student(const Student &stu) {
            p = new int[stu.arr_num];
            for (int i = 0; i < arr_num; i++) {
                p[i] = stu.p[i];
            }
        }
    public:
        void set_Name(string name);
        string get_Name() {return name_;}
        void set_Sex(string sex);
        string get_Sex() {return sex_;}
        void study(int score);
        int get_Score() {return score_;}
        void print();
    private:
        string name_;
        string sex_;
        int score_ = 0;
        int arr_num = 5;
        int *p = nullptr;
};

Student::Student(string name, string sex) : name_(name), sex_(sex) {
    p = new int[arr_num];
    if (!p) {
        cout << "out of memory" << endl;
        exit(1);
    }
    for (int i = 0; i < arr_num; i++)
    {
        p[i] = i;
    }
}

void Student::set_Name(string name) {
    name_ = name;
}

void Student::set_Sex(string sex) {
    sex_ = sex;
}

void Student::study(int score) {
    score_ += score; 
}

void Student::print() {
    cout << "name:" << name_ << " sex:" << sex_ << " score:" << score_ << endl;
    for (int i = 0; i < arr_num; i++)
    {
        cout << "p" << i << ":" << p[i] << endl;
    }
}

int main()
{
    Student stu1("puhao", "male");
    Student stu2(stu1);
    stu1.print();
    stu2.print();
}
