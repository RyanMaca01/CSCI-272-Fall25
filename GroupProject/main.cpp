#include "grades.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
  
  string student_name;
  cout << "Enter Student Name (First and Last): ";
  getline(cin, student_name);
  //This is good!

Student one(student_name);
    int numCourses;
      cout << "Enter number of courses (1–10): ";
      cin >> numCourses;
      cin.ignore();
// Loop through each course
// cleaned up this area, didn't need the int classes part   
    
for (int i = 0; i < numCourses; i++) {
      string courseName, letterGrade;
      int creditHours;

      cout << "\nEnter course name: ";
      cin.clear();
      getline(cin, courseName);
     // cout << courseName;

      cout << "Enter credit hours: ";
      cin >> creditHours;

      cout << "Enter letter grade (A, A-, B+, B, etc.): ";
      cin >> letterGrade;
      cin.ignore();

      Course c(courseName, creditHours, letterGrade);
      one.addCourse(c);
    
  }


  // Transcript part
  //Randol + Noeleen coding and debugging + Ryan (me) looking over it!!!
  cout << "\n--- Transcript for " << student_name << " ---\n\n";
  cout << left << setw(20) << "Course" << setw(10) << "Credits" << setw(10) << "Grade" << setw(10) << "Points" << endl;

  cout << "----------------------------------------\n";

  double totalCredits = 0, totalPoints = 0;

  for (const Course& c : one.getCourses()) {
      double coursePoints = c.getTotalPoints();
      totalCredits += c.getCreditHours();
      totalPoints += coursePoints;

      cout << left << setw(20) << c.getCourseName() << setw(10) << c.getCreditHours() << setw(10) << c.getLetterGrade() << fixed << setprecision(2) << coursePoints << endl;
  }
  cout << "----------------------------------------\n";
  double gpa = one.calculateGPA();
  cout << "Total Points: " << fixed << setprecision(2) << totalPoints << endl;
  cout <<"\nTotal Credits: " << totalCredits << endl;
  cout << "GPA: " << fixed << setprecision(2) << gpa << endl;

  if (gpa >= 3.7) 
      cout << "Dean's List" << endl;
  else if (gpa >= 2.0)
      cout << "Good Standing" << endl;
  else
      cout << "Probation" << endl;

  return 0;
}

/*Include a short header comment with your name, date, and at the end of the code, write a 3–5 sentence reflection (what was tricky / what you learned).
Group Members: Ryan Maca, Randol Cespedes, and Noeleen Herbert
Here is what we found tricky, Ryan Had trouble with formatting the h file, and 
then making sure the classes had the right functions. Randol had trouble with 
getting the transcript output to line up nealty with using setw and formatting 
the GPA correctly was confusing at first. Me (Noeleen) I had to debug the code and 
make sure the code was running correclty but I had trouble getting the points to display correctly. 
We learned how to commuicate and divide the work and how to use the setw function to format the output.
*/