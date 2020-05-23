#include "Gate.hpp"

Gate::Gate(Gate_type type, int number_of_gate_inputs, int output_id, vector<int> input_ids) {
	label = type;
	value = 0;
	for(int i = 0; i< number_of_gate_inputs; i++) {
		if(input_ids[i] == -1) {
			throw Duplicate_Id_Exception();
		}
		Input gate_input(input_ids[i]);
		inputs.push_back(gate_input);
	}
	if(output_id == -1) {
		throw Duplicate_Id_Exception();
	}
	id_of_output = output_id;
	number_of_inputs = number_of_gate_inputs; 
}

void Gate::change_input_value(int input_id, int new_value) {
	if( input_id == -1)
		throw Override_By_Two_Driver();
	if(new_value != 0 && new_value != 1)
		throw Invalid_Value();
	for(int i = 0; i < inputs.size(); i++) {
		if(inputs[i].ID == input_id) {
			inputs[i].value = new_value;
			inputs[i].state_of_containing_value = 1;
			return;
		}
	}
	return;
}

int Gate::eval() {
	return value;
}


And_Gate::And_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids) : Gate(And, number_of_gate_inputs, output_id, input_ids) {

} 

void And_Gate::update_value() {
	for(int i = 0; i< inputs.size(); i++) {
		if(inputs[i].get_value() == 0) {
			value = 0;
			return;
		}
	}
	value = 1;
	return;
}



Or_Gate::Or_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids) : Gate(Or, number_of_gate_inputs, output_id, input_ids) {

} 

void Or_Gate::update_value() {
	for(int i = 0; i< inputs.size(); i++) {
		if(inputs[i].get_value() == 1) {
			value = 1;
			return;
		}
	}
	value = 0;
	return;
}


Xor_Gate::Xor_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids) : Gate(Xor, number_of_gate_inputs, output_id, input_ids) {

} 

void Xor_Gate::update_value() {
	int size_of_ones = 0;
	int size_of_zeros = 0;
	for(int i = 0; i< inputs.size(); i++) {
		if(inputs[i].get_value() == 0)
			size_of_zeros ++;
		else
			size_of_ones ++;
	}
	if(size_of_ones % 2 != 0)
		value = 1;
	else
		value = 0;
}



Not_Gate::Not_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids) : Gate(Not, number_of_gate_inputs, output_id, input_ids) {
	if(number_of_gate_inputs != 1) {
		throw Number_Of_Not_Inputs_Exception();
	}

} 

void Not_Gate::update_value() {
	if(inputs[0].get_value() == 0)
		value = 1;
	else
		value = 0;
}



Nor_Gate::Nor_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids) : Gate(Nor, number_of_gate_inputs, output_id, input_ids) {

} 

void Nor_Gate::update_value() {
	for(int i = 0; i< inputs.size(); i++) {
		if(inputs[i].get_value() == 1) {
			value = 0;
			return;
		}
	}
	value = 1;
	return;	
}



Nand_Gate::Nand_Gate(int number_of_gate_inputs, int output_id, vector<int> input_ids) : Gate(Nand, number_of_gate_inputs, output_id, input_ids) {

} 

void Nand_Gate::update_value() {
	for(int i = 0; i< inputs.size(); i++) {
		if(inputs[i].get_value() == 0) {
			value = 1;
			return;
		}
	}
	value = 0;
	return;
}
