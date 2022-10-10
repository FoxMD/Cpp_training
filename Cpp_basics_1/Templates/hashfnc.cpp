#include <iostream>
#include <unordered_set>
#include <string>

class Employee
{
    std::string m_Name;
    int m_Id;
    public:
        Employee(const std::string &n, int id) : m_Name(n), m_Id(id)
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
    coll.insert(Employee{"King", 123});
    coll.insert(Employee{"Bob", 678});
    coll.insert(Employee{"Joey", 612});

    for(const auto &element: coll)
    {
        std::cout << element.GetId() << ": " << element.GetName() << std::endl;
    }
}

// better to use hash lass from boost library

int main()
{
    Hashes();
    return 0;
}