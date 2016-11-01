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
    output << "Student " << that.getName() << ":" << endl << endl;
    output << "Courses:" << endl;
    for (int i = 0; i < that.getNumCourses(); i++) {
        output << "\tCourse #" << i+1 << ": " << that.getCourses()[i] << endl;
    }
    return output;
}

int main(int argc, const char * argv[]) {
    string name;
    cout << endl << "Input student name: ";
    getline(cin,name);
    cin.clear();
    string temp;
    
    Student student = *new Student(name);
    while (true) {
        cout << endl << "Next course: ";
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
    Student student2 = *new Student(student);
    cout << endl << student;
    cout << endl << "Continue? (Y,n): ";
    getline(cin,temp);
    cin.clear();
    if (temp!="n"&&temp!="N") main(argc, argv);
    return 0;
}
