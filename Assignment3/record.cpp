#include "record.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
bool Record::add_profile(std::string id, std::string name, std::string phone) {
  if (student_record.find(id) != student_record.end()) {
    std::cout << "Record Exists\n";
    return false;
  }
  StudentRecord record = {
    .id = id,
    .name = name,
    .phone = phone
  };
  student_record[id] = record;
  return true;
}

bool Record::del_profile(std::string id) {
  std::map<std::string, StudentRecord>::iterator itr = student_record.find(id);
  if (itr == student_record.end()) {
    std::cout << "Record Not Exists\n";
    return false;
  }
  student_record.erase(itr);
  for (std::vector<GradeRecord>::iterator itr = grade_record.begin();
        itr != grade_record.end();
        ) {
          if (itr->stu_id == id) {
            itr=grade_record.erase(itr);
            continue;
          }
          itr++;
        }
  return true;
}

bool Record::add_grade(std::string id, std::string class_id, double grade) {
  bool found = false;
  for (std::vector<GradeRecord>::iterator itr = grade_record.begin();
      itr != grade_record.end();
      itr++) {
        if (itr->stu_id == id && itr->class_id == class_id) {
          found = true;
          break;
        }
  }
  if (found) {
    std::cout << "Record Exists\n";
    return false;
  } else {
    GradeRecord record = {
      .grade = grade,
      .class_id = class_id,
      .stu_id = id
    };
    grade_record.push_back(record);
    return true;
  }
}

bool Record::del_grade(std::string id, string class_id) {
  bool found = false;
  std::vector<GradeRecord>::iterator del_itr;
  for (std::vector<GradeRecord>::iterator itr = grade_record.begin();
      itr != grade_record.end();
      itr++) {
        if (itr->stu_id == id && itr->class_id == class_id) {
          found = true;
          del_itr = itr;
          break;
        }
  }
  if (!found) {
    std::cout << "Record Not Exists\n";
    return false;
  } else {
    grade_record.erase(del_itr);
    return true;
  }
}

bool record_comp(GradeRecord& g_a, GradeRecord& g_b) {
  return g_a.grade < g_b.grade;
}

bool stu_comp(StudentRecord& s_a, StudentRecord& s_b) {
  return s_a.name < s_b.name;
}

void Record::display_grades(std::string class_id){
  std::vector<GradeRecord> result_set;
  for (std::vector<GradeRecord>::iterator itr = grade_record.begin();
        itr != grade_record.end();
        itr++) {
          if (itr->class_id == class_id)
            result_set.push_back(*itr);
        }
  sort(result_set.begin(), result_set.end(), record_comp);
  for (std::vector<GradeRecord>::iterator itr = result_set.begin();
      itr != result_set.end();
      itr++) {
        std::cout << student_record[itr->stu_id].name << " " << itr->stu_id << " " << itr->grade << "\n";
      }
}

void Record::display_profiles(){
  std::vector<StudentRecord> result_set;
  for (std::map<std::string, StudentRecord>::iterator itr = student_record.begin();
        itr != student_record.end();
        itr++) {
          result_set.push_back(itr->second);
  }
  sort(result_set.begin(), result_set.end(), stu_comp);
  for (std::vector<StudentRecord>::iterator itr = result_set.begin();
      itr != result_set.end();
      itr++) {
        std::cout << itr->id << " " << itr->name << " " << itr->phone << "\n";
      }
}
