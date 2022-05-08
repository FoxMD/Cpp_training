#include <iostream>

class Employee;
class Project
{
    public:
        Employee *m_emp;
        Project() { std::cout << "Project()" << std::endl;}
        ~Project() { std::cout << "~Project()" << std::endl;}
};

class Employee
{
    public:
        Project *m_prj;
        Employee(){ std::cout << "Employee()" << std::endl;}
        ~Employee(){ std::cout << "~Employee()" << std::endl;}
};

int main()
{
    Employee *emp = new Employee{};
    Project *prj = new Project{};

    emp->m_prj = prj;
    prj->m_emp = emp;

    delete emp;
    delete prj;
    return 0;
}