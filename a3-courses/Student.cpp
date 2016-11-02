//
//  Student.cpp
//  a3-courses
//
//  Created by Alexander Cochrane on 2016-10-31.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class Student {
public:
    std::string name;
    int numCourses = 0;
    std::string *courseList = new std::string[numCourses];
    
    Student(){}
    
    Student(const std::string name) : name(name) {}
    
    Student(const Student& that)
    : name(that.name), numCourses(that.numCourses) {
        this->courseList = new std::string[numCourses];
        for (int i = 0; i < numCourses; i++) {
            this->courseList[i] = that.courseList[i];
        }
        std::cout << std::endl << "Copied student." << std::endl;
    }
    
    Student& operator=(const Student& that) {
        return *new Student(that);
    }
    
    friend std::ostream& operator << (const std::ostream& output, const Student& that);
    
    void addCourse(std::string courseName) {
        std::string* temp = new std::string[this->numCourses];
        
        for (int i = 0; i < this->numCourses; i++) {
            temp[i] = this->courseList[i];
        }
        
        this->numCourses++;
        this->courseList = new std::string[this->numCourses];
        
        for (int i = 0; i < this->numCourses; i++) {
            if (i == this->numCourses - 1) {
                this->courseList[i] =  courseName;
            }
            else {
                this->courseList[i] = temp[i];
            }
        }
        
        delete[] temp;
    }
    
    void setName(std::string name) {
        this->name=name;
    }
    
    int getNumCourses() {
        return this->numCourses;
    }
    
    // Destructor
    ~Student() {
        std::cout << std::endl << "Deleted student named " << this->name << std::endl;
        delete [] courseList;
    }
    
};
