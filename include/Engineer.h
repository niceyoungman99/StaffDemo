//
// Created by maxim on 23.04.2024.
//

#ifndef STAFFDEMO_INCLUDE_ENGINEER_H_
#define STAFFDEMO_INCLUDE_ENGINEER_H_
#include <iostream>
#include <string>
#include <utility>
#include "Personal.h"
#include "Interfaces.h"
#include "Factory.h"
class Engineer : public Personal, public Project_Budget {
 public:
  Engineer(int id, std::string name, Positions position, int workTime, int salary,
           Project project);
  int calc_budget_part() override;//подсчитывает какую часть бюджета проекта получит работник
  void calc() override;//подсчитывает общую зарплату
  void SetPart_in_project(float part);//устанавливает часть,которую получит работник из бюджета проекта
  int GetPrId();//возвращает айди проекта, в котором участвует работник
  //virtual void print_info() override; not in positions
 protected:
  Project project = Project(0, 0, 0);
  float part_in_project = 0.0;
};
class Tester : public Engineer {
 public:
  Tester(int id, std::string name, Positions position,
         int workTime, int salary, Project project);
  int calc_pro_additions() override;//подсчитывает зарплату тестировщика за найденные ошибки
  void calc() override;//общий подсчет зарплаты
  void Set_for_one_mistake(int hmfom);//установить плату за одну найденную ошибку
  void print_info() override;//вывод информации о работнике
  virtual int calc_bonus_salary(int bonus);
  void SetCount_of_mistakes(int count);//устанавливает сколько ошибок нашел и исправил тестировщик
  //void SetPart_in_project(float part);
 protected:
  int count_of_mistakes = 0;
  int how_much_for_one_mistake = 0;
  //float part_int_project;//should we do it????????
};
class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, Positions position,
             int workTime, int salary, Project project);
  int calc_pro_additions() override;//выплачивает сумму,расчитанную за досрочное завершение
  void calc() override;//общий подсчет зарплаты
  void setDosrok(bool d);//устанавливает выполнил ли программист задачу досрочно
  void setPremia(int p);//устанавливает размер премии за досрочную работу
  void print_info() override;//вывод информации о работнике
  virtual int calc_bonus_salary(int bonus);
 protected:
  bool dosrok = false;
  int premia = 0;
};
class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, Positions position,
             int workTime, int salary, Project project);
  void calc() override;//посчет общей зарплаты
  void Set_fee(int f);//устанавливает плату за руководство
  int calc_Heads() override;//оплата за руководство
 protected:
  int fee_for_heading = 0;
};

#endif //STAFFDEMO_INCLUDE_ENGINEER_H_
