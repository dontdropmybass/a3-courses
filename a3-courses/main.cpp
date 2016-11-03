//
//  main.cpp
//  a3-courses
//
//  Created by Alexander Cochrane 2016-10-31
//

#include "Student.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

//  overloaded << operator
//
//  used to output a student object
//
//  example:
//
//      Student Alex:
//
//          Courses:
//              Course 1: C++
//              Course 2: PHP
//              Course 3: J2EE
ostream& operator << (ostream& output, Student& that) {
    output << "Student " << that.name << ":" << endl << endl;
    output << "Courses:" << endl;
    for (int i = 0; i < that.numCourses; i++) {
        output << "\tCourse #" << i+1 << ": " << that.courseList[i] << endl;
    }
    return output;
}

//  main
//  takes input to define Student objects
int main() {
    string name;
    cout << endl << "Input student name: ";
    getline(cin,name);
    cin.clear();
    Student student = Student(name);
    
    //  Loops continuously, adding new courses to the Student object.
    //  Ends only when user enters an empty string
    while (true) {
        string temp;
        cout << endl << "\tNext course: ";
        temp.clear();
        getline(cin,temp);
        cin.clear();
        if (temp=="") {
            break;
        }
        else {
            student.addCourse(temp);
        }
    }
    //  End while true
    
    //  print out student
    cout << endl << student;
    _getch();
    
    //  get the name of a new student
    cout << endl << "Input student name: ";
    name.clear();
    getline(cin,name);
    
    //  copy the original student into a second student
    Student student2 = Student(student);
    
    //  delete the original student
    student.~Student();
    
    //  set the second students name to the name retrieved earlier
    student2.setName(name);
    
    //  print out second student
    cout << endl << student2;
    
    //  ask if they want to do it all again
    cout << endl << "Continue? (Y,n): ";
    string temp;
    getline(cin,temp);
    cin.clear();
    
    //  Goes back to the start unless user enters n or N
    if (temp!="n"&&temp!="N") main();
    return 0;
}
