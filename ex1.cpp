#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
using namespace std;
class stu {
    private:
        string name;
        char sex;
    public:
        stu();
        stu(string stu_name, char stu_sex) : name(stu_name), sex(stu_sex) {};
        ~stu() {};
    public:
        friend class stu_mgr;
        void is_sex() const;
        void print_stu() const;
        stu &print_name();
};

class stu_mgr {
    public:
        using stuIndex = vector<stu>::size_type;
        void clear(stuIndex);
    private:
        vector<stu> stus{stu("puhao", 'm')};
};
void stu_mgr::clear(stuIndex i) {
    stu &s = stus[i]; 
    s.name = "";
    s.sex = 0;
}

void stu::print_stu() const {
    cout << "student name: " << name << " student sex: " << sex << endl;
}

void stu::is_sex() const {
    if (sex == 'm')
        cout << name << " is man" << endl;
    else if (sex == 'f')
        cout << name << " is female" << endl;
}

stu &stu::print_name(){
    return *this;
}

struct personinfo {
    string name;
    vector<string> phone_number;
};

int main()
{
    stu s2("lijiang", 'f');
    stu s1("puhao", 'm'); 
    s1.print_stu();
    s2.is_sex();
    stu_mgr s1m;
    cout << "------------" << endl;
    ofstream out("file.in", fstream::trunc);
    out << "hi";
    ifstream in("file.in", fstream::in);
    string s;
    in >> s; 
    cout << s << endl;
    cout << "----------- " << endl;

    vector<personinfo> people;
    string line, word;

    while (getline(cin, line))
    {
        personinfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phone_number.push_back(word);
        people.push_back(info);
    }

    for (auto &i : people)
    { 
        cout << "name: " << i.name << "  ";
        for (auto &j : i.phone_number)
            cout << "phone number: " << j << " ";
        cout << endl;
    }

    return 0;
}
