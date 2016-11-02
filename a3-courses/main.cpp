//
//  main.cpp
//  a3-courses
//
//  Created by Alexander Cochrane on 2016-10-31.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include "Student.hpp"


using namespace std;

ostream& operator << (ostream& output, Student& that) {
    output << "Student " << that.name << ":" << endl << endl;
    output << "Courses:" << endl;
    for (int i = 0; i < that.numCourses; i++) {
        output << "\tCourse #" << i+1 << ": " << that.courseList[i] << endl;
    }
    return output;
}

int main() {
    string name;
    cout << endl << "Input student name: ";
    getline(cin,name);
    cin.clear();
    Student student = Student(name);
    
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
    cout << endl << student;
    _getch();
    cout << endl << "Input student name: ";
    name.clear();
    getline(cin,name);
    Student student2 = Student(student);
    student2.setName(name);
    cout << endl << student2;
    cout << endl << "Continue? (Y,n): ";
    string temp;
    getline(cin,temp);
    cin.clear();
    if (temp!="n"&&temp!="N") main();
}
