
#ifndef STAFFDEMO_INCLUDE_PERSONAL_H_
#define STAFFDEMO_INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
 public:
  Personal(int id, std::string name, Positions position, int workTime, int salary);
  virtual ~Personal();
  //void print_info() override;
  int calc_base_salary() override;//подсчет почасовой оплаты
 protected:
  int salary = 0;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, Positions position, int work_time, int salary);
  void calc() override;//подсчет общей зарплаты
  int calc_bonus_salary(int bonus = 4) override;//подсчет зарплаты за ночные часы
  void print_info() override;//вывод информации
  void Set_Night_hours(int nh);//сеттер для ночных часов
 protected:
  int night_hours = 0;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, Positions position, int work_time, int salary);
  void calc() override;//подсчитывает общую зарплату
  void print_info() override;//вывод информации
  virtual int calc_bonus_salary(int bonus) override;//подсчет зарплаты
};
#endif //STAFFDEMO_INCLUDE_PERSONAL_H_
