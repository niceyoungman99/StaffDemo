#include "Employee.h"
Employee::Employee(int id, std::string name, Positions position, int work_time)
    : id(id), name(name), work_time(work_time), position(position) {
  this->id = id;
  this->name = name;
  this->work_time = work_time;
  this->position = position;
}
void Employee::print_info() {//
  //std::cout<<"ID - "<<id<<",Name - "<<name<<" ,Work_time - "<<work_time<<" ,Position - "<<position<<",Payment - "<<payment<<std::endl;
}
void Employee::setWorkTime(int work_time) {
  this->work_time = work_time;
}
int Employee::Get_ID() const {
  return id;
}
std::string Employee::GetPosition() const {
  switch (position) {
    case Positions::programmer: {
      return "programmer";
    }
    case Positions::team_leader: {
      return "team_leader";
    }
    case Positions::project_manager: {
      return "project_manager";
    }
    case Positions::senior_manager: {
      return "senior_manager";
    }
    case Positions::cleaner: {
      return "cleaner";
    }
    case Positions::driver: {
      return "driver";
    }
    case Positions::tester: {
      return "tester";
    }
    case Positions::unemployed: {
      return "unemployed";
    }
  }
}
std::vector<std::string> Employee::Get_Enum_Print() const {
  return enum_print;
}
Project::Project(int id, int budget, int number_of_employees) {
  this->id = id;
  this->budget = budget;
  this->number_of_employees = number_of_employees;
}
int Project::get_num_of_employees() const {
  return number_of_employees;
}
int Project::get_budget() const {
  return budget;
}
int Project::get_id() const {
  return id;
}
