
#include <string>
using namespace std;

class Record{
private:
  // Define some data structure here to store the data
public:
  // Return true if succeed, false otherwise
  bool add_profile(string id, string name, string phone);
  bool del_profile(string id);
  bool add_grade(string id, string class_id, double grade);
  bool del_grade(string id, string class_id);

  your_data_structure get_profiles();
  your_data_structure get_grades();
}

/* other neccessary defination here */
