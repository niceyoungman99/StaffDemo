#include <iostream>
#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"
#include "Interfaces.h"
#include "Factory.h"
#include "Manager.h"
#include <windows.h>
int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru");
  std::cout<<"Необязательно пробовал создавать работников(не из файла)"<<std::endl;
  Driver g(1,"Grigory",driver,4,8);
  g.Set_Night_hours(15);
  g.calc();
  g.print_info();
  Cleaner first(1,"Bob",cleaner,23,100);
  first.calc();
  first.print_info();
  Project p(99,1000000,5);
  Tester l(2,"Tamara",tester,4,56,p);
  l.SetPart_in_project(0.05);
  l.Set_for_one_mistake(1000);
  l.calc();
  l.print_info();
  Programmer q(11,"Roman",programmer,6,123,p);
  q.SetPart_in_project(0.1);
  q.setDosrok(true);
  q.setPremia(10000);
  q.calc();
  q.print_info();
  TeamLeader w(12,"Oleg",team_leader,10,200,p);
  w.SetPart_in_project(0.22);
  w.Set_fee(10000);
  w.calc();
  w.print_info();
  ProjectManager e(99,"Eduard",project_manager,100,9999,p);
  e.SetPart_in_project(0.28);
  e.Set_fee_for_member_in_project(20000);
  e.calc();
  e.print_info();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  Factory_Staff factory;
  factory.setProjects();
  std::cout<<"Вывод информации о проектах:"<<std::endl;
  for (int i = 0; i < factory.GetProjects().size(); i++) {
    std::cout << "Project`s id - " << factory.GetProjects()[i]->get_id() << ", Project`s budget - "
              << factory.GetProjects()[i]->get_budget() << ", Project`s number of employees - "
              << factory.GetProjects()[i]->get_num_of_employees() << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  factory.setPersons();
  std::cout << "Вывод работников до подсчета зарплаты" << std::endl;
  //std::cout<<factory.GetStaff().size()<<std::endl;
  for (int i = 0; i < factory.GetStaff().size(); i++) {
    factory.GetStaff()[i]->print_info();
    std::cout << std::endl;
  }
  for (int i = 0; i < factory.GetStaff().size(); i++) {
    factory.GetStaff()[i]->calc();
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Вывод работников после подсчета зарплаты" << std::endl;
  for (int i = 0; i < factory.GetStaff().size(); i++) {
    factory.GetStaff()[i]->print_info();
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Вывод программистов после подсчета зарплаты" << std::endl;
  //здесь пользователь может установить премии,части бюджета проектов программистам в зависимости от их проекта
  for (int i = 0; i < factory.GetStaff().size(); i++){//зная то что в 1 проекте 3 программиста во 2 проекте - 2, мы можем проставить премии и части бюджета преокта им прямо здесь
    if(factory.GetStaff()[i]->GetPosition()=="programmer"){
      Programmer * A=dynamic_cast<Programmer*>(factory.GetStaff()[i]);
      if(A->GetPrId()==1){
        A->setPremia(15000);
        A->calc();
      }
      else if(A->GetPrId()==0){
        A->setDosrok(true);
        A->setPremia(1000000);
        A->calc();
      }
      else if(A->GetPrId()==2){
        A->SetPart_in_project(0.02);
        A->calc();
      }
      else{
        A->setPremia(1000000000);
        A->calc();
      }
    A->print_info();
    }
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Вывод тестировщиков после подсчета зарплаты" << std::endl;
  //здесь пользователь может установить количество ошибок,плату за них,части бюджета проектов тестировщикам в зависимости от их проекта
  for (int i = 0; i < factory.GetStaff().size(); i++){
    if(factory.GetStaff()[i]->GetPosition()=="tester"){
      Tester * A=dynamic_cast<Tester*>(factory.GetStaff()[i]);
      if(A->GetPrId()==1){
        A->SetCount_of_mistakes(10000);
        A->Set_for_one_mistake(10000);
        A->calc();
      }
      else if(A->GetPrId()==0){
        A->SetPart_in_project(0.02);
        A->calc();
      }
      else if(A->GetPrId()==2){
        A->SetPart_in_project(0.03);
        A->calc();
      }
      else{
        A->setWorkTime(10000);
        A->calc();
      }
      A->print_info();
    }

  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Вывод тимлидов после подсчета зарплаты" << std::endl;
  //здесь пользователь может установить плату за руководство,части бюджета проектов тимлидам в зависимости от их проекта
  for (int i = 0; i < factory.GetStaff().size(); i++){
    if(factory.GetStaff()[i]->GetPosition()=="team_leader"){
      TeamLeader * A=dynamic_cast<TeamLeader*>(factory.GetStaff()[i]);
      if(A->GetPrId()==1){
        A->Set_fee(100000);
        A->calc();
      }
      else if(A->GetPrId()==0){
        A->SetPart_in_project(0.045);
        A->calc();
      }
      else if(A->GetPrId()==2){
        A->Set_fee(2000000);
        A->calc();
      }
      else{
        A->setWorkTime(10000);
        A->calc();
      }
      A->print_info();
    }
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Вывод проджект-менеджеров после подсчета зарплаты" << std::endl;
  //здесь пользователь может установить плату за руководство людьми,части бюджета проектов проджект менеджерам в зависимости от их проекта
  for (int i = 0; i < factory.GetStaff().size(); i++){
    if(factory.GetStaff()[i]->GetPosition()=="project_manager"){
      ProjectManager * A=dynamic_cast<ProjectManager*>(factory.GetStaff()[i]);
      if(A->GetPrId()==1){
        A->Set_fee_for_member_in_project(1000000);
        A->calc();
      }
      else if(A->GetPrId()==0){
        A->SetPart_in_project(0.065);
        A->calc();
      }
      else if(A->GetPrId()==2){
        A->Set_fee_for_member_in_project(2000000);
        A->calc();
      }
      else{
        A->setWorkTime(100000);
        A->calc();
      }
      A->print_info();
    }
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Вывод сеньор-менеджеров после подсчета зарплаты" << std::endl;
  //здесь пользователь может установить плату за руководство людьми,части бюджета проектов сеньерам в зависимости от их проекта
  for (int i = 0; i < factory.GetStaff().size(); i++){
    if(factory.GetStaff()[i]->GetPosition()=="senior_manager"){
      SeniorManager * A=dynamic_cast<SeniorManager*>(factory.GetStaff()[i]);
      A->Set_fee_for_member_in_project(10000000);
      A->SetPart_in_project(0.2);
      A->calc();
      A->print_info();
    }
  }
}