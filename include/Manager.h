
#ifndef STAFFDEMO_INCLUDE_MANAGER_H_
#define STAFFDEMO_INCLUDE_MANAGER_H_
#include "Interfaces.h"
#include "Employee.h"
#include "Factory.h"
class ProjectManager : public Heading, public Project_Budget, public Employee, public Factory_Staff {
 public:
  void print_info() override;//выводит информацию о работнике
  ProjectManager(int id, std::string name, Positions position,
                 int workTime, int salary, Project project);
  int calc_Heads() override;//подсчет денег за руководство
  void calc() override;//подсчет общей зарплаты
  void Set_fee_for_member_in_project(int f);//сеттер платы за руководство людьми в проекте
  void SetProject(Project p);
  int calc_budget_part() override;//подсчитывает какую часть из бюджета проекта получит данный работник
  virtual int calc_pro_additions() override;
  void SetPart_in_project(float p);//устанавливает часть,которую работник будет получать из бюджета проекта
  int GetPrId();//возвращает айди проекта в котором участвует работник
 protected:
  int salary;
  Project project = Project(0, 0, 0);
  float part_in_pr = 0;
  int fee_for_heading = 0;
};
class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, Positions position,
                int workTime, int salary, Project project, std::vector<Project *> prs);
  int calc_Heads() override;//подсчитывает плату за руководство
  void SetPr_to_Prs(Project *t);
  int calc_budget_part() override;//подсчитывает какую часть из бюджета проекта получит данный работник
  void print_info() override;//выводит информацию о работнике
 protected:
  std::vector<Project *> prs;

};
#endif //STAFFDEMO_INCLUDE_MANAGER_H_
