#ifndef __INPUT_HPP__
#define __INPUT_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include "Wire.hpp"
#include "Gate.hpp"
#include "circuit.hpp"
#include "Exceptions.hpp"

using namespace std;


class Wire;
class Gate;
class Circuit;
class Invlaid_User;

class Input {
public:
	Input(int _ID);
	int get_id();
	int get_value();
	void set_value(int _value);
	bool state_of_value();
	friend class Wire;
	friend class Gate;
	friend class Circuit;
private:
	int ID;
	int value;
	bool state_of_connection_to_other_gates;
	bool state_of_containing_value;
};

#endif