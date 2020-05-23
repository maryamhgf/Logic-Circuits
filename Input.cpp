#include "Input.hpp"

Input::Input(int _ID) {
	ID = _ID;
	state_of_connection_to_other_gates = 0;
	state_of_containing_value = 0;
}

bool Input::state_of_value() {
	return state_of_containing_value;
}

int Input::get_id() {
	return ID;
}

int Input::get_value() {
	return value;
}

void Input::set_value(int _value) {
	if(_value != 0 && _value != 1)
		throw Invalid_Value();
	value = _value;
	state_of_containing_value = 1;
}