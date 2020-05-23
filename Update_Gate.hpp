#ifndef __UPDATE_GATE_HPP__
#define __UPDATE_GATE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "Gate.hpp"
#include "Input.hpp"
#include "Exceptions.hpp"
#include "Wire.hpp"
#include "circuit.hpp"

using namespace std;

class Gate;
class And_Gate;
class Nand_Gate;
class Nor_Gate;
class Or_Gate;
class Xor_Gate;
class Not_Gate;
class Bad_Initialization;
class Input;
class Wire;
class Circuit;

void update_gate(Gate* gate, int the_end);

#endif