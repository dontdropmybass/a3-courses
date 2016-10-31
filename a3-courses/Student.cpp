//
//  Student.cpp
//  a3-courses
//
//  Created by Alexander Cochrane on 2016-10-31.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Student {
private:
    std::string name;
    int numCourses = 0;
    int currentCourse = 0;
    std::string *courseList = new std::string[0];
    Student(){}
public:
    
    Student(const std::string& name, int numCourses) : name(name), numCourses(numCourses) {
        this->courseList = new std::string[numCourses];
    }
    
    Student(const Student& that)
    : name(that.name), numCourses(that.numCourses), courseList(that.courseList) {}
    
    Student& operator=(const Student& that) {
        return *new Student(that);
    }
    
    friend std::ostream& operator << (const std::ostream& output, const Student& that);
    
    void addCourse(std::string courseName) {
        this->courseList[currentCourse++] = courseName;
    }
    
    std::string getCourses() {
        return *this->courseList;
    }
    
    std::string getName() {
        return this->name;
    }
    
    int getNumCourses() {
        return this->numCourses;
    }
    
    // Destructor
    ~Student() {
        delete[] this->courseList;
    }
    
};
