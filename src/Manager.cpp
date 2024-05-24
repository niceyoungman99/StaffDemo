#include "Manager.h"
ProjectManager::ProjectManager(int id,
                               std::string name, Positions position,
                               int workTime,
                               int salary, Project project
) : Employee(id, name, position, workTime) {//??????prrrrrrrrrrrrrrrrrr
  this->salary = salary;
  this->project = project;

}
void ProjectManager::Set_fee_for_member_in_project(int f) {
  this->fee_for_heading = f;
}
int ProjectManager::calc_Heads() {
  return project.get_num_of_employees() * fee_for_heading;
}
void ProjectManager::calc() {
  payment = calc_Heads() + calc_budget_part();
}
void ProjectManager::print_info() {
  std::cout << "ID - " << Get_ID() << ", Name - " << name << ", Work_time - " << work_time << ", Position - "
            << GetPosition() << ", Payment - " << payment << ", Salary - " << salary << ", Project_ID - "
            << project.get_id() << ", Part in project - " << part_in_pr << std::endl;
}
int ProjectManager::calc_budget_part() {
  return project.get_budget() * part_in_pr;
}
int ProjectManager::calc_pro_additions() {
  return 0;
}
void ProjectManager::SetProject(Project p) {
  project = p;
}
void ProjectManager::SetPart_in_project(float p) {
  this->part_in_pr = p;
}
int ProjectManager::GetPrId() {
  return project.get_id();
}
SeniorManager::SeniorManager(int id,
                             std::string name,
                             Positions position,
                             int workTime,
                             int salary,
                             Project project,
                             std::vector<Project *> prs) : ProjectManager(id,
                                                                          name,
                                                                          position,
                                                                          workTime,
                                                                          salary,
                                                                          project) {
  this->prs = prs;
}//we should to give count of prs to SenMan
void SeniorManager::SetPr_to_Prs(Project *t) {
  prs.push_back(t);
}
int SeniorManager::calc_Heads() {
  int sum = 0;
  for (int i = 0; i < prs.size(); i++) {
    sum += prs[i]->get_num_of_employees() * fee_for_heading;
  }
  return sum;
}
int SeniorManager::calc_budget_part() {
  int sum = 0;
  for (int i = 0; i < prs.size(); i++) {//todo: this person have a part from all projects of our factory
    sum += prs[i]->get_budget() * part_in_pr;
  }
  return sum;
}
void SeniorManager::print_info() {
  std::cout << "ID - " << Get_ID() << ", Name - " << name << ", Work_time - " << work_time << ", Position - "
            << GetPosition() << ", Payment - " << payment << ", Salary - " << salary << ", Count of projects - "
            << prs.size() << ", Part in projects - " << part_in_pr << std::endl;
}