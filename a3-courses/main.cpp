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
    output << "Classes:" << endl;
    for (int i = 0; i < that.getNumCourses(); i++) {
        output << "\t" << i+1 << that.getCourses()[i] << endl;
    }
    return output;
}

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

int main(int argc, const char * argv[]) {
    string name;
    int numCourses;
    cout << endl << "Input student name: ";
    cin >> name;
    string temp;
    cout << endl << "Input number of courses student is in: ";
checknum:
    cin >> temp;
    if (!is_number(temp)) {
        temp.clear();
        cout << endl << "That is not a valid number. Try again: ";
        goto checknum;
    }
    else {
        numCourses = stoi(temp);
    }
    
    Student student = *new Student(name,numCourses);
    
    cout << endl << "Enter the courses:" << endl;
    for (int i = 0; i < numCourses; i++) {
        cout << "Course #" << i + 1 << ": ";
        temp.clear();
        cin >> temp;
        student.addCourse(temp);
    }
    temp.clear();
    cout << endl << student;
    cout << endl << "Continue? (Y,n): ";
    cin >> temp;
    if (temp!="n"&&temp!="N") main(argc, argv);
    return 0;
}
