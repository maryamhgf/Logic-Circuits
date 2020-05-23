#ifndef __Exceptions_HPP__
#define __Exceptions_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>

using namespace std;

enum Gate_type {And, Or, Not, Xor, Nand, Nor};

class Duplicate_Id_Exception : public exception {
  virtual const char* what() const throw();
};

class Invalid_Id : public exception {
  virtual const char* what() const throw();
};

class Invalid_Value : public exception {
  virtual const char* what() const throw();
};

class Bad_Initialization : public exception {
  virtual const char* what() const throw();
};

class Override_By_Two_Driver : public exception {
  virtual const char* what() const throw();
};

class Number_Of_Not_Inputs_Exception : public exception {
  virtual const char* what() const throw();
};

#endif


