#include <iostream>
#include <string>
#include <vector>
using namespace std;


//This is Ryan's part of the Code
class Course{
//Private
private: 
string CourseName;
int CreditHours;
string LetterGrade;

//Public
public:
Course(string name, int credits, string grade){

  CourseName = name;
  CreditHours = credits;
  LetterGrade = grade;

  }

//These are the getters
string getCourseName() const {
  return CourseName;
}

int getCreditHours() const {
  return CreditHours;
}


string getLetterGrade() const {
  return LetterGrade;
}


//The GPA points conversion
//Noeleen help me with this, yaya!
//we looked online about the whole points chart: Ex: A = 4.0 
double letterToPoints(string grade) const
{
  
  if (grade == "A" || grade == "A+")  // a grade of A or A+ both equal 4.0
  return 4.0;
    
  else if (grade == "A-")
  return 3.7;
    
  else if (grade == "B+")
  return 3.3;
    
  else if (grade == "B")
  return 3.0;

  else if (grade == "B-")
  return 2.7;

  else if (grade == "C+")
  return 2.3;
    
  else if (grade == "C")
  return 2.0;

  else if (grade == "C-")
  return 1.7;

  else if (grade == "D+")
  return 1.3;
  
  else if (grade == "D")
  return 1.0;

  else if (grade == "D-")
  return 0.7;
    
  else if (grade == "F")
  return 0.0;
    
  else
  return 0.0;
}


//Calculate total points for that course
double getTotalPoints() const {
  return CreditHours*letterToPoints(LetterGrade);
}

};

//Ryan + Noeleen looking over it 
class Student{
//Private
private: 
string StudentName;
vector<Course>Courselist;

//Public
public:
Student(string studentName){
  StudentName = studentName;
}

// Add course to the list
void addCourse(Course c){
    Courselist.push_back(c);
}

// Get the list of courses
vector<Course> getCourses() const {
    return Courselist;
}


//Calculate GPA using range loop
double calculateGPA() {
  double totalPoints = 0.0;
  double totalCredits = 0.0;

for (Course c : Courselist){
  totalPoints += c.getTotalPoints();
  totalCredits += c.getCreditHours();
}

  if (totalCredits == 0)
    return 0.0;
  else
    return totalPoints / totalCredits;

}



};