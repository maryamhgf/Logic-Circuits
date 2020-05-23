#ifndef __WIRE_HPP__
#define __WIRE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include "Gate.hpp"
#include "Input.hpp"
#include "circuit.hpp"
#include "Update_Gate.hpp"
#include "Exceptions.hpp"

using namespace std;

class Gate;
class And_Gate;
class Nand_Gate;
class Nor_Gate;
class Or_Gate;
class Xor_Gate;
class Not_Gate;
class Circuit;
class Bad_Initialization;
class Invalid_Id;
class Override_By_Two_Driver;
void update_gate(Gate* gate, int the_end);
class Input;

class Wire {
public:
	Wire(Gate* source, Gate* destination, int source_input_id, int dest_input_id);
	void connect_head_to_tail();
	friend class Gate;
	friend class Circuit;
private:
	Gate* source_gate;
	Gate* destination_gate;
	int source_gate_input_id;
	int dest_gate_input_id;
};

#endif