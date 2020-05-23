#include "Exceptions.hpp"

const char* Bad_Initialization::what() const throw() {
    return "Bad initialization." ;
}

const char* Duplicate_Id_Exception::what() const throw() {
    return "‫‪Duplicate‬‬ ‫‪ID.‬‬";
}

const char* Invalid_Id::what() const throw() {
    return "Invalid ID." ;
}

const char* Invalid_Value::what() const throw() {
    return "Invalid value." ;
}

const char* Override_By_Two_Driver::what() const throw() {
   return "Override by two driver." ;
}

const char* Number_Of_Not_Inputs_Exception::what() const throw() {
    return "‫‪‫‪Not‬‬ ‫‪should‬‬ ‫‪have‬‬ ‫‪1‬‬ ‫‪input.‬‬";
}