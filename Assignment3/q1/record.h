
#include <string>
#include <vector>
#include <map>
using namespace std;

typedef struct student_record_t {
  std::string id;
  std::string name;
  std::string phone;
} StudentRecord;

typedef struct grade_record_t {
  double grade;
  std::string class_id;
  std::string stu_id;
} GradeRecord;

class Record{
private:
  // Define some data structure here to store the data
  std::map<std::string, StudentRecord> student_record;
  // std::map<std::string, ClassRecord> class_record;
  std::vector<GradeRecord> grade_record;
public:
  // Return true if succeed, false otherwise
  bool add_profile(string id, string name, string phone);
  bool del_profile(string id);
  bool add_grade(string id, string class_id, double grade);
  bool del_grade(string id, string class_id);

  void display_profiles();
  void display_grades(std::string);
};

/* other neccessary defination here */
