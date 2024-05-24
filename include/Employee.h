
#ifndef STAFFDEMO_INCLUDE_EMPLOYEE_H_
#define STAFFDEMO_INCLUDE_EMPLOYEE_H_
#include "iostream"
#include <string>
#include <vector>

enum Positions {
  programmer,
  team_leader,
  project_manager,
  senior_manager,
  cleaner,
  driver,
  tester,
  unemployed,

};
class Project {
 public:
  Project(int id, int budget, int number_of_employees);
  int get_num_of_employees() const;//возвращает количество работников в проекте
  int get_budget() const;//возвращает бюджет проекта
  int get_id() const;//возвращает айди проекта
 private:
  int id;
  int budget;
  int number_of_employees;
};
class Employee {
 public:
  Employee(int id, std::string name, Positions position, int work_time);
  virtual void calc() = 0;
  virtual void print_info() = 0;
  void setWorkTime(int work_time);//устанавливает рабочее время работника
  int Get_ID() const;//возвращает айди работника
  std::string GetPosition() const;//функция для вывода енама позиций работников
  std::vector<std::string> Get_Enum_Print() const;
  int Get_Project_ID() const;
 private:
  int id;
 protected:
  Positions position;
  int payment = 0;
  int work_time;
  std::string name;
  std::vector<std::string> enum_print = {"programmer",
                                         "team_leader",
                                         "project_manager",
                                         "senior_manager",
                                         "cleaner",
                                         "driver",
                                         "tester"};
};

#endif //STAFFDEMO_INCLUDE_EMPLOYEE_H_
