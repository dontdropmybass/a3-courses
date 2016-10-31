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
    std::string *courseList = new std::string;
    Student(){}
public:
    
    Student(const std::string& name, int numCourses) : name(name), numCourses(numCourses) {}
    
    Student(const std::string& name, int numCourses, std::string courseList[])
    : name(name), numCourses(numCourses), courseList(courseList) {}
    
    Student(const Student& that)
    : name(that.name), numCourses(that.numCourses), courseList(that.courseList) {}
    
    Student& operator=(const Student& that) {
        return *new Student(that.name,that.numCourses,that.courseList);
    }
    
    friend std::ostream& operator << (const std::ostream& output, const Student& that);
    
    void addCourse(std::string courseName) {
        this->courseList[this->numCourses] = courseName;
        this->numCourses++;
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
        delete this->courseList;
    }
    
};
