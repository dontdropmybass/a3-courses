//
//  Student.hpp
//  a3-courses
//
//  Created by Alexander Cochrane 2016-10-31
//
 
//  if this header is not defined
#ifndef Student_hpp
//  define this header
#define Student_hpp

//  include the student class
#include "Student.cpp"

//  These are some unix (mac) specific definitions
//  for functions that are otherwise not available
#define _getch() system("read -n1 -p 'Press any key...\n' key");
#define _cls()   std::cout << string(50, '\n');

#endif /* Student_hpp */
