//
// Created by maxim on 23.04.2024.
//

#ifndef STAFFDEMO_INCLUDE_INTERFACES_H_
#define STAFFDEMO_INCLUDE_INTERFACES_H_
class Heading {
 public:
  virtual ~Heading() = default;
  virtual int calc_Heads() = 0;
};

class Work_Base_Time {
 public:
  virtual ~Work_Base_Time() = default;
  virtual int calc_bonus_salary(int bonus) = 0;
  virtual int calc_base_salary() = 0;
};

class Project_Budget {
 public:
  virtual ~Project_Budget() = default;;
  virtual int calc_budget_part() = 0;
  virtual int calc_pro_additions() = 0;
};

#endif //STAFFDEMO_INCLUDE_INTERFACES_H_
