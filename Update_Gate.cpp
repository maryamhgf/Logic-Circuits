#include "Update_Gate.hpp"

using namespace std;

void update_gate(Gate* gate, int the_end) {
	if(gate == NULL)
		throw Invalid_Id();
	if(the_end == 1){
		for(int i = 0; i < gate->number_of_inputs; i++) {
			if(gate->inputs[i].state_of_value() == 0) {
				throw Bad_Initialization();
			}
		}
	}
	if(And_Gate* and_gate = dynamic_cast <And_Gate*> (gate)) {
		and_gate->update_value();
	}
	else if(Or_Gate* or_gate = dynamic_cast <Or_Gate*> (gate)) {
		or_gate->update_value();
	}
	if(Nand_Gate* nand_gate = dynamic_cast <Nand_Gate*> (gate)) {
		nand_gate->update_value();
	}
	if(Nor_Gate* nor_gate = dynamic_cast <Nor_Gate*> (gate)) {
		nor_gate->update_value();
	}
	if(Xor_Gate* xor_gate = dynamic_cast <Xor_Gate*> (gate)) {
		xor_gate->update_value();
	}
	if(Not_Gate* not_gate = dynamic_cast <Not_Gate*> (gate)) {
		not_gate->update_value();
	}
}
