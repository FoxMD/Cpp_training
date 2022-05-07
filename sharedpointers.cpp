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
    Project *m_pProject{};
    public:
        void SetProject(Project *prj)
        {
            m_pProject = prj;
        }
        const Project* GetProject()const 
        {
            return m_pProject;
        }
};

void ShowInfo(const std::unique_ptr<Employee>)