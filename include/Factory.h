//
// Created by maxim on 23.04.2024.
//

#ifndef STAFFDEMO_INCLUDE_FACTORY_H_
#define STAFFDEMO_INCLUDE_FACTORY_H_
#include <string>
#include <vector>
#include <map>
#include "Personal.h"
#include "Employee.h"
#include "fstream"
class Factory_Staff {
 public:
  std::vector<Employee *> make_staff;
  std::vector<Project *> our_projects;
  void setProjects();//устанавливает проекты
  void setPersons();//анимает работников
  std::vector<Employee *> GetStaff();//возвращает вектор работников
  std::vector<Project *> GetProjects();//возвращает вектор проектов

};

#endif //STAFFDEMO_INCLUDE_FACTORY_H_
