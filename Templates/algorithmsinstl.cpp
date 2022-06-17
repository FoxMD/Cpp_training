#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>

class Employee
{
    std::string m_Name;
    int m_Id;
    std::string m_ProgLang;
    public:
        Employee(const std::string &n, int id, const std::string &lang) : m_Name(n), m_Id(id), m_ProgLang(lang)
        {

        }
        const std::string & GetName()const
        {
            return m_Name;
        }
        int GetId()const
        {
            return m_Id;
        }
        const std::string & GetProgLang()const
        {
            return m_ProgLang;
        }

        // for sort algorithm
        bool operator < (const Employee &e)const
        {
            return m_Id < e.m_Id;
        }
};

struct EmployeeHash
{
    size_t operator()(const Employee &emp)const{
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};

struct EmpEquality
{
   bool operator()(const Employee &emp1, const Employee &emp2) const
   {
        return emp1.GetId() == emp2.GetId() && emp1.GetName() == emp2.GetName();
   } 
};

void Hashes()
{
    std::hash<std::string> h;
    std::cout << "Hash: " << h("hello") << std::endl;
    std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
    coll.insert(Employee{"King", 123, "C"});
    coll.insert(Employee{"Bob", 678, "C"});
    coll.insert(Employee{"Joey", 612, "C"});

    for(const auto &element: coll)
    {
        std::cout << element.GetId() << ": " << element.GetName() << std::endl;
    }
}

void UserDefinedVector()
{
    std::vector<Employee> v{
        Employee{"Tina", 101, "C++"},
        Employee{"Max", 202, "Java"},
        Employee{"Tatra", 200, "Rust"}
    };
    std::sort(v.begin(), v.end());  // to use it implement < and > for class
    // we can overload the function to use callback as a predicate (bool type function)
    std::sort(v.begin(), v.end(), [](const auto &e1, const auto &e2) {
        return e1.GetName() < e2.GetName();
    });

    for(const auto &e : v)
    {
        std::cout << "ID: " << e.GetId() << " name: " << e.GetName() << " programming: " << e.GetProgLang() << std::endl;
    }
}

struct EmpCompare
{
    bool operator()(const Employee &e1, const Employee &e2) const
    {
        return e1.GetId() < e2.GetId();
    }
};

void UserDefinedSet()
{
    std::set<Employee, EmpCompare> s{
        Employee{"Tina", 101, "C++"},
        Employee{"Max", 202, "Java"},
        Employee{"Tatra", 200, "Rust"}
    };

    for(const auto &e : s)
    {
        std::cout << "ID: " << e.GetId() << " name: " << e.GetName() << " programming: " << e.GetProgLang() << std::endl;
    }
}

int main()
{
    Hashes();
    return 0;
}