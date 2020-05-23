#ifndef __Circuit_HPP__
#define __Circuit_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include "Gate.hpp"
#include "Wire.hpp"
#include "Update_Gate.hpp"
#include "Exceptions.hpp"
#include "Input.hpp"

using namespace std;

class Wire;
class Gate;
class Input;
class And_Gate;
class Nand_Gate;
class Nor_Gate;
class Or_Gate;
class Xor_Gate;
class Not_Gate;
class Duplicate_Id_Exception;
class Invalid_Id;
class Invalid_Value;
class Bad_Initialization ;
class Override_By_Two_Driver;
class Number_Of_Not_Inputs_Exception ;

void update_gate(Gate* gate, int the_end);

class Circuit {
    public:
        void add_gate_to_circuit(const Gate_type gate, const int number_of_gate_inputs, const int output_id, 
                                 const int input1_id, ...) noexcept;
        void connect(const int first_id, const int second_id) noexcept;
        void put_value_on_gate_input(const int input_id, const int value) noexcept;
        void print_gate_output(const int output_id) noexcept;
        int find_index_of_gate_by_input_id(int input_id);
        int find_index_of_gate_by_output_id(int output_id);
        void delete_heap();
    private:
        vector <Gate*> gates;
        vector <Wire*> wires;
};

#endif