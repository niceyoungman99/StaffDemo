#include "Engineer.h"
#include "Factory.h"
Engineer::Engineer(int id, std::string name, Positions position, int workTime, int salary, Project project) : Personal(
    id,
    name,
    position,
    workTime,
    salary) {
  this->project = project;
}
void Engineer::SetPart_in_project(float part) {
  this->part_in_project = part;
}
int Engineer::calc_budget_part() {
  return project.get_budget() * part_in_project;
}
void Engineer::calc() {
  payment = calc_base_salary() + calc_budget_part();
}
//void Engineer::print_info() {
//  std::cout<<"ID - "<<Get_ID()<<",Name - "<<name<<" ,Work_time - "<<work_time<<" ,Position - "<<position<<",Payment - "<<payment<<" ,Salary - "<<salary<<" ,Project_ID - "<<project.get_id()<<" ,Part in project - "<<part_in_project<<std::endl;
//}
int Engineer::GetPrId() {
  return project.get_id();
}
Tester::Tester(int id,
               std::string name,
               Positions position,
               int workTime,
               int salary,
               Project project
) : Engineer(id, name, position, workTime, salary, project) {
}
void Tester::Set_for_one_mistake(int hmfom) {
  this->how_much_for_one_mistake = hmfom;
}
int Tester::calc_pro_additions() {
  return this->count_of_mistakes * this->how_much_for_one_mistake;
}
void Tester::calc() {
  payment = calc_base_salary() + calc_pro_additions() + calc_budget_part();
}
void Tester::print_info() {
  std::cout << "ID - " << Get_ID() << ", Name - " << name << ", Work_time - " << work_time << ", Position - "
            << GetPosition() << ", Payment - " << payment << ", Salary - " << salary << ", Project_ID - "
            << project.get_id() << ", Part in project - " << part_in_project << std::endl;
}
int Tester::calc_bonus_salary(int bonus) {
  return 0;
}
void Tester::SetCount_of_mistakes(int count) {
  this->count_of_mistakes = count;
}
Programmer::Programmer(int id, std::string name, Positions position, int workTime, int salary, Project project)
    : Engineer(id, name, position, workTime, salary, project) {}
void Programmer::setDosrok(bool d) {
  dosrok = d;
}
void Programmer::setPremia(int p) {
  premia = p;
}
int Programmer::calc_pro_additions() {
  if (dosrok == true) {
    return premia;
  } else {
    return 0;
  }
}
void Programmer::calc() {
  payment = calc_pro_additions() + calc_base_salary() + calc_budget_part();
}
void Programmer::print_info() {
  std::cout << "ID - " << Get_ID() << ", Name - " << name << ", Work_time - " << work_time << ", Position - "
            << GetPosition() << ", Payment - " << payment << ", Salary - " << salary << ", Project_ID - "
            << project.get_id() << ", Part in project - " << part_in_project << std::endl;
}
int Programmer::calc_bonus_salary(int bonus) {
  return 0;
}
TeamLeader::TeamLeader(int id,
                       std::string name,
                       Positions position,
                       int workTime,
                       int salary,
                       Project project) : Programmer(id, name, position, workTime, salary, project) {}
void TeamLeader::Set_fee(int f) {
  fee_for_heading = f;
}
int TeamLeader::calc_Heads() {
  return fee_for_heading * 2;
}
void TeamLeader::calc() {
  payment = calc_Heads() + calc_base_salary() + calc_budget_part();
}