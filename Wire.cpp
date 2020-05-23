#include "Wire.hpp"


int find_in_vector_of_inputs_wire(vector<Input> vector_of_inputs, int ID) {
	if(ID == -1)
		throw Invalid_Id();
	for(int i = 0; i < vector_of_inputs.size(); i++ ) {
		if(ID == vector_of_inputs[i].get_id()) {
			return i;
		}
	}
}

Wire::Wire(Gate* source, Gate* destination, int source_input_id, int dest_input_id) {
	if(source_input_id == -1 || dest_input_id == -1)
		throw Override_By_Two_Driver();
	source_gate = source;
	destination_gate = destination;
	source_gate_input_id = source_input_id;
	dest_gate_input_id = dest_input_id;
}

void Wire::connect_head_to_tail() {
	int index_of_input_node = find_in_vector_of_inputs_wire(destination_gate->inputs, dest_gate_input_id);
	destination_gate->inputs[index_of_input_node].set_value(source_gate->value);
	destination_gate->inputs[index_of_input_node].state_of_connection_to_other_gates = 1;
	update_gate(destination_gate, 0);
}
