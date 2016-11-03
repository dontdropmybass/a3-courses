//
//  Student.cpp
//  a3-courses
//
//  Created by Alexander Cochrane on 2016-10-31.
//

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

//
//  Student class
//  has a name, a number of courses, and an array of courses
//
class Student {
public:
    std::string name;
    int numCourses = 0;
    std::string *courseList = new std::string[numCourses];
    
    // default empty constructor
    Student(){}
    
    //  takes a name and creates a blank student with that name
    Student(const std::string name) : name(name) {}
    
    //  takes an existing student object and creates a deep copy
    //  (new student object with same field values)
    Student(const Student& that)
    : name(that.name), numCourses(that.numCourses) {
        this->courseList = new std::string[numCourses];
        for (int i = 0; i < numCourses; i++) {
            this->courseList[i] = that.courseList[i];
        }
        std::cout << std::endl << "Copied student." << std::endl;
    }
    
    //  sets one student object equal to another
    Student& operator=(const Student& that) {
        std::cout << std::endl << "Assigned " << that.name << " to new student." << std::endl;
        return *new Student(that);
    }
    
    friend std::ostream& operator << (const std::ostream& output, const Student& that);
    
    //  funtion to add a course
    //  takes one course at a time and adds it to the course array
    void addCourse(std::string courseName) {
        //  create a temporary array to store old data
        std::string* temp = new std::string[this->numCourses];
        
        //  populate temporary array with existing data
        for (int i = 0; i < this->numCourses; i++) {
            temp[i] = this->courseList[i];
        }
        
        //  increment number of courses
        this->numCourses++;
        
        //  recreate the course array
        this->courseList = new std::string[this->numCourses];
        
        //  add data back into the course array
        for (int i = 0; i < this->numCourses; i++) {
            
            //  if on the last member of the course array, add the new course
            if (i == this->numCourses - 1) {
                this->courseList[i] =  courseName;
            }
            //  otherwise add the course already in the temporary course array
            else {
                this->courseList[i] = temp[i];
            }
        }
        
        //  delete the temporary array to keep from having memory leaks
        delete[] temp;
    }
    
    //  sets the name of the student
    void setName(std::string name) {
        this->name=name;
    }
    
    //  returns the number of courses this student is enrolled in
    int getNumCourses() {
        return this->numCourses;
    }
    
    //  reset student to empty name, 0 courses, empty course array
    void reset() {
        this->name = "";
        this->numCourses = 0;
        delete [] this->courseList;
        this->courseList = new std::string[numCourses];
    }
    
    // Destructor
    ~Student() {
        std::cout << std::endl << "Deleted student named " << this->name << std::endl;
        delete [] this->courseList;
    }
    
};
