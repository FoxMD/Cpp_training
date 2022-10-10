#include <iostream>
#include <memory>

class Project
{
    std::string m_Name;
    public:
        void SetName(const std::string &name)
        {
            m_Name = name;
        }
        void ShoProjectDetails()const 
        {
            std::cout << "Project name" << m_Name << std::endl;
        }
};

class Employee
{
    std::shared_ptr<Project> m_pProject{};
    public:
        void SetProject(std::shared_ptr<Project> &prj)
        {
            m_pProject = prj;
        }
        const std::shared_ptr<Project> &GetProject()const 
        {
            return m_pProject;
        }
};

void ShowInfo(const std::unique_ptr<Employee> &emp)
{
    std::cout << "Employee: ";
    emp->GetProject()->ShoProjectDetails();
}

int main()
{
    std::shared_ptr<Project> prj {new Project{}};
    prj->SetName("First");
    std::shared_ptr<Employee> e1 {new Employee{}};
    std::shared_ptr<Employee> e2 {new Employee{}};

    e1->SetProject(prj);
    e2->SetProject(prj);

    std::cout << prj.use_count() << std::endl; // used only for debugging to check reference counter

    prj->ShoProjectDetails();

    return 0;
}