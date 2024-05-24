#include "Personal.h"
Personal::Personal(int id, std::string name, Positions position, int workTime, int salary) : Employee(id,
                                                                                                      name,
                                                                                                      position,
                                                                                                      workTime) {
  this->salary = salary;
}
/*void Personal::print_info() {maybe really it is not necessary
  std::cout<<"ID - "<<Get_ID()<<",Name - "<<name<<" ,Work_time - "<<work_time<<" ,Position - "<<position<<",Payment - "<<payment<<" ,Salary - "<<salary<<std::endl;//right??
}*/
int Personal::calc_base_salary() {
  payment = salary * work_time;
  return payment;
}
Personal::~Personal() noexcept {
  name = " ";
  position = unemployed;
}

Cleaner::Cleaner(int id, std::string name, Positions position, int work_time, int salary) : Personal(id,
                                                                                                     name,
                                                                                                     position,
                                                                                                     work_time,
                                                                                                     salary) {}
void Cleaner::calc() {
  payment = calc_base_salary();

}
void Cleaner::print_info() {
  std::cout << "ID - " << Get_ID() << ", Name - " << name << ", Work_time - " << work_time << ", Position - "
            << GetPosition() << ", Payment - " << payment << ", Salary - " << salary << std::endl;
}
Driver::Driver(int id, std::string name, Positions position, int work_time, int salary) : Personal(id,
                                                                                                   name,
                                                                                                   position,
                                                                                                   work_time,
                                                                                                   salary) {

}
int Driver::calc_bonus_salary(int bonus) {//todo: i give to driver parametr night hours to count bonus payment
  return night_hours * salary;
}
void Driver::calc() {
  payment = calc_base_salary() + calc_bonus_salary();//???
}
void Driver::print_info() {
  std::cout << "ID - " << Get_ID() << ", Name - " << name << ", Work_time - " << work_time << ", Position - "
            << GetPosition() << ", Payment - " << payment << ", Salary - " << salary << ", Night hours - "
            << night_hours
            << std::endl;
}
int Cleaner::calc_bonus_salary(int bonus) {
  return 0;
}
void Driver::Set_Night_hours(int nh) {
  this->night_hours = nh;
}