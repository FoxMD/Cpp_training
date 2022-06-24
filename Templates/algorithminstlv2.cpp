#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

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
        // for count algorithm
        bool operator == (const Employee &e)const
        {
            return m_ProgLang == e.m_ProgLang;
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

struct EmpIDs
{
    std::vector<int> m_IDs;
    void operator()(const Employee &e){
        if(e.GetProgLang() == "C++"){
            m_IDs.push_back(e.GetId());
        }
    }
};

void UserDefinedVector()
{
    std::vector<Employee> v{
        Employee{"Tina", 101, "C++"},
        Employee{"Max", 202, "Java"},
        Employee{"Tatra", 200, "Rust"}
    };

    std::sort(v.begin(), v.end(), [](const auto &e1, const auto &e2) {
        return e1.GetName() < e2.GetName();
    });

    int cppCount{};
    for(const auto &e : v)
    {
        if(e.GetProgLang() == "C++") cppCount++;
        std::cout << "ID: " << e.GetId() << " name: " << e.GetName() << " programming: " << e.GetProgLang() << std::endl;
    }

    std::cout << cppCount << std::endl;
    // the above counting can be missunderstood or too complex in some cases
    // stl library offers count function for some specific type
    cppCount = std::count(v.begin(), v.end(), Employee{"", 0, "C++"}); // we need overload == or use count_if

    cppCount = std::count_if(v.begin(), v.end(), [](const auto &e){
        return e.GetProgLang() == "C++";
    });

    auto itr = std::find_if(v.begin(), v.end(), [](const auto &e){
        return e.GetProgLang() == "Java";
    });
    if(itr != v.end())
    {
        std::cout << "Found java programmer: " << itr->GetName() << std::endl;
    }

    std::for_each(v.begin(), v.end(), [](const auto &e){
        std::cout << e.GetName() << "\n";
    }); // it does return each element

    auto foundIDs = std::for_each(v.begin(), v.end(), EmpIDs());
    for(const auto id: foundIDs.m_IDs)
    {
        std::cout << "Id: " << id << std::endl;
    }
}

int main()
{
    UserDefinedVector();
    return 0;
}

/* Changes from 11+:
    - containers use noexcept specifiers (on iterators)
    - containers have brace initializer
        - std::vector<int> myVec{1,2,3,4,5}
    - they preffer std::move before copy
    - emplace/emplace_back were added
        - emplace makes a construction of object
        - push placec an existing object
        - example:
            - std::vector<std::pair><int, std::string>> data;
            - data.push_back(std::pair<int, std::string>{100, "C++"});
            - data.emplace_back(100, "C++");
    - for use of move operation on our classes we need to specify noexcept on move operations(move constructor and operator)

*/