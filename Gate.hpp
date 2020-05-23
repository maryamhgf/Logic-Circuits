#ifndef __GATE_HPP__
#define __GATE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include "Wire.hpp"
#include "circuit.hpp"
#include "Exceptions.hpp"
#include "Input.hpp"
#include "Update_Gate.hpp"

using namespace std;

class Wire;
class Circuit;
class Duplicate_Id_Exception;
class Invalid_Value;
class Input;
void update_gate(Gate* gate, int the_end);

class Gate {
public:
	Gate(Gate_type type, int number_of_gate_inputs, int output_id, vector<int> input_ids);
	virtual void update_value() = 0;
	int eval();
	void change_input_value(int input_id, int new_value);
	friend class Wire;
	friend class Circuit;
	friend void update_gate(Gate* gate, int the_end);
protected:
	Gate_type label;
	int value;
	vector<Input> inputs;  
	int id_of_output;
	int number_of_inputs;
	friend class Wire;
};

class And_Gate : public Gate {
public:
	And_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids);
	void update_value();
};

class Or_Gate : public Gate {
public:
	Or_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids);
	void update_value();
};

class Xor_Gate : public Gate {
public:
	Xor_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids);
	void update_value();
};

class Not_Gate : public Gate {
public:
	Not_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids);
	void update_value();
};

class Nor_Gate : public Gate {
public:
	Nor_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids);
	void update_value();
};

class Nand_Gate : public Gate {
public:
	Nand_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids);
	void update_value();
};

#endif
