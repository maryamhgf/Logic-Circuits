#include "circuit.hpp"

#define FAIL 0
#define NOT_FOUND -1

int find_in_vector_of_inputs(vector<Input> vector_of_inputs, int ID) {
	if(ID == -1)
		throw Invalid_Id();
	for(int i = 0; i < vector_of_inputs.size(); i++ ) {
		if(ID == vector_of_inputs[i].get_id()) {
			return i;
		}
	}
}

void Circuit::delete_heap() {
	for(int i = 0; i < gates.size(); i++)
		delete gates[i];
	for(int i = 0; i < wires.size(); i++)
		delete wires[i];
}

void Circuit::add_gate_to_circuit(const Gate_type gate, const int number_of_gate_inputs, const int output_id, const int input1_id, ...) noexcept {
	try {
	vector<int> input_ids;
	input_ids.push_back(input1_id);
	int output_id_used_to_creat;
	if( find_index_of_gate_by_output_id(output_id) != NOT_FOUND || find_index_of_gate_by_input_id(output_id) != NOT_FOUND)
		output_id_used_to_creat = -1;
	else
		output_id_used_to_creat = output_id;
    va_list args;
    va_start(args, input1_id);
    for(int i = 0; i < number_of_gate_inputs-1 ; i++) 
        input_ids.push_back(va_arg(args, int));
    va_end(args);

    for(int i = 0; i < input_ids.size(); i++) {
    	if(find_index_of_gate_by_input_id(input_ids[i]) != NOT_FOUND || find_index_of_gate_by_output_id(input_ids[i]) != NOT_FOUND)
    		input_ids[i] = NOT_FOUND;
    }

	if(gate == And) {
		And_Gate* and_gate = new And_Gate(number_of_gate_inputs, output_id_used_to_creat, input_ids);
		gates.push_back(and_gate);
	}
	else if( gate == Or) {
		Or_Gate* or_gate = new Or_Gate(number_of_gate_inputs, output_id_used_to_creat, input_ids);
		gates.push_back(or_gate);
	}
	else if( gate == Xor) {
		Xor_Gate* xor_gate = new Xor_Gate(number_of_gate_inputs, output_id_used_to_creat, input_ids);
		gates.push_back(xor_gate);
	}
	else if( gate == Nand) {
		Nand_Gate* nand_gate = new Nand_Gate(number_of_gate_inputs, output_id_used_to_creat, input_ids);
		gates.push_back(nand_gate);
	}
	else if( gate == Nor) {
		Nor_Gate* nor_gate = new Nor_Gate(number_of_gate_inputs, output_id_used_to_creat, input_ids);
		gates.push_back(nor_gate);
	}
	else if( gate == Not) {
		Not_Gate* not_gate = new Not_Gate(number_of_gate_inputs, output_id_used_to_creat, input_ids);
		gates.push_back(not_gate);
	}
} catch(exception& new_exception) {
	cout<< new_exception.what()<<endl;
	delete_heap();
	exit(FAIL);
	return;
}
}


int Circuit::find_index_of_gate_by_input_id(int input_id) {
	for (int i = 0; i<gates.size(); i++) {
		vector<Input> vector_of_input = gates[i]->inputs;
		for(int j = 0; j < vector_of_input.size(); j++) {
			if(vector_of_input[j].ID == input_id) 
				return i;
		}
	}
	return NOT_FOUND;
}

int Circuit::find_index_of_gate_by_output_id(int output_id) {
	for (int i = 0; i<gates.size(); i++) {
		if(gates[i]->id_of_output == output_id)
			return i;
	}
	return NOT_FOUND;
}

void Circuit::connect(const int first_id, const int second_id) noexcept{
	try {
	int index_of_source_gate = find_index_of_gate_by_output_id(first_id);
	int source_wire_id = first_id;
	if(index_of_source_gate == NOT_FOUND) {
		index_of_source_gate = find_index_of_gate_by_output_id(second_id);
		source_wire_id = second_id;
	}
	int index_of_dest_gate = find_index_of_gate_by_input_id(first_id);
	int dest_wire_id = first_id;
	if(index_of_dest_gate == NOT_FOUND) {
		index_of_dest_gate = find_index_of_gate_by_input_id(second_id);
		dest_wire_id = second_id;
	}
	if(find_index_of_gate_by_output_id(first_id) !=NOT_FOUND && find_index_of_gate_by_output_id(second_id) != NOT_FOUND){
		source_wire_id = NOT_FOUND;
		dest_wire_id = NOT_FOUND;
	}
	Wire* wire = new Wire(gates[index_of_source_gate],gates[index_of_dest_gate], source_wire_id, dest_wire_id);
	wire->connect_head_to_tail();
	wires.push_back(wire);
} catch(exception& new_exception) {
	cout<< new_exception.what()<<endl;
	delete_heap();
	exit(FAIL);
	return;
}
}

void Circuit::put_value_on_gate_input(const int input_id, const int value) noexcept{
	try{
	vector<Input> inputs_of_gate;
	int input_id_to_find;
	int index_of_gate = find_index_of_gate_by_input_id(input_id);
	if(index_of_gate == NOT_FOUND) 
		input_id_to_find = NOT_FOUND;
	else {
		input_id_to_find = input_id;
		inputs_of_gate = gates[index_of_gate]->inputs;
	}
	int index_of_input_in_gate = find_in_vector_of_inputs(inputs_of_gate, input_id);
	if(gates[index_of_gate]->inputs[index_of_input_in_gate].state_of_connection_to_other_gates == 1) 
		input_id_to_find = NOT_FOUND;
	gates[index_of_gate]->change_input_value(input_id_to_find, value);
	for (int i = 0; i < wires.size() ; i++) {
		wires[i]->connect_head_to_tail();
	}
	update_gate(gates[index_of_gate], 0);
} catch(exception& new_exception) {
	cout<< new_exception.what()<<endl;
	delete_heap();
	exit(FAIL);
	return;
}
}

void Circuit::print_gate_output(const int output_id) noexcept{
	try{
	int index_of_gate = find_index_of_gate_by_output_id(output_id);
	if(index_of_gate == NOT_FOUND)
		update_gate(NULL, 0);
	else
		update_gate(gates[index_of_gate], 1);
	cout<<"The current output of gate with id " << output_id<< " is " <<gates[index_of_gate]->value << endl;
}catch(exception& new_exception) {
	cout<< new_exception.what()<<endl;
	delete_heap();
	exit(FAIL);
	return;
}
}
