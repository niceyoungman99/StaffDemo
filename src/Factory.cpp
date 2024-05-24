#include "Factory.h"
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"

void Factory_Staff::setProjects() {
  // открываем файл,делаем считывание,создаем объекты проектов,пушим их в вектор проектов
  std::ifstream st("C:\\Users\\maxim\\CLionProjects\\StaffDemo\\projects_info.txt");
  if (st.fail()) {
    std::cout << "Opening error!" << std::endl;
  }
  while (!st.eof()) {
    Project *project;
    int id, budget, number_members;
    st >> id;
    st >> budget;
    st >> number_members;
    project = new Project(id, budget, number_members);
    our_projects.push_back(project);
  }
  st.close();
}

void Factory_Staff::setPersons() {
  //открываем файл,делаем считывание,создаем объекты работников,пушим их в вектор работников
  std::ifstream st("C:\\Users\\maxim\\CLionProjects\\StaffDemo\\staff_info.txt");
  if (st.fail()) {
    std::cout << "Opening error!" << std::endl;
  }
  while (!st.eof()) {
    int id = 0, project_id = 0, salary = 0, work_time = 0;
    std::string name1, name2, name3;
    Positions position;
    st >> id;
    st >> name1 >> name2 >> name3;
    std::string position_key;
    st >> position_key;
    st >> work_time;
    st >> salary;
    st >> project_id;
    std::string fullname = name1 + " " + name2 + " " + name3;
    if (position_key == "programmer") {
      for (int i = 0; i < our_projects.size(); i++) {
        if (project_id == our_projects[i]->get_id()) {
          Project *project = our_projects[i];
          Programmer *employee = new Programmer(id, fullname, programmer, work_time, salary, *project);
          employee->SetPart_in_project(0.04);//default
          employee->setDosrok(true);//default
          employee->setPremia(4000);//default
          make_staff.push_back(employee);
          continue;
        }
      }
    }
    if (position_key == "team_leader") {
      for (int i = 0; i < our_projects.size(); i++) {
        if (project_id == our_projects[i]->get_id()) {
          Project *project = our_projects[i];
          TeamLeader *employee = new TeamLeader(id, fullname, team_leader, work_time, salary, *project);
          employee->Set_fee(1000);//default
          employee->SetPart_in_project(0.09);//default
          make_staff.push_back(employee);
          continue;
        }
      }
    }
    if (position_key == "project_manager") {
      for (int i = 0; i < our_projects.size(); i++) {
        if (project_id == our_projects[i]->get_id()) {
          Project *project = our_projects[i];
          ProjectManager *employee = new ProjectManager(id, fullname, project_manager, work_time, salary, *project);
          employee->Set_fee_for_member_in_project(1500);//default
          employee->SetPart_in_project(0.13);//default
          make_staff.push_back(employee);
          continue;
        }
      }
    }
    if (position_key == "senior_manager") {
      Project project = Project(0, 0, 0);
      std::vector<Project *> prs = our_projects;
      SeniorManager
          *employee = new SeniorManager(id, fullname, senior_manager, work_time, salary, project, our_projects);
      employee->Set_fee_for_member_in_project(2000);//default
      employee->SetPart_in_project(0.2);//default
      make_staff.push_back(employee);
      continue;
    }
    if (position_key == "cleaner") {
      Cleaner *employee = new Cleaner(id, fullname, cleaner, work_time, salary);
      make_staff.push_back(employee);
      continue;
    }
    if (position_key == "driver") {
      Driver *employee = new Driver(id, fullname, driver, work_time, salary);
      employee->Set_Night_hours(15);//default
      make_staff.push_back(employee);
      continue;
    }
    if (position_key == "tester") {
      for (int i = 0; i < our_projects.size(); i++) {
        if (project_id == our_projects[i]->get_id()) {
          Project *project = our_projects[i];
          Tester *employee = new Tester(id, fullname, tester, work_time, salary, *project);
          employee->SetPart_in_project(0.04);//default
          employee->SetCount_of_mistakes(7);//also
          employee->Set_for_one_mistake(400);//also
          make_staff.push_back(employee);
          continue;
        }
      }
    }
  }

  st.close();

}
std::vector<Employee *> Factory_Staff::GetStaff() {
  return make_staff;
}
std::vector<Project *> Factory_Staff::GetProjects() {
  return our_projects;
}