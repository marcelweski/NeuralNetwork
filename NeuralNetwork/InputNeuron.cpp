#include "InputNeuron.hpp"

NeuralNetwork::InputNeuron::InputNeuron() : value(0.0)
{}

double NeuralNetwork::InputNeuron::getValue()
{
	return this->value;
}
void NeuralNetwork::InputNeuron::setValue(double value)
{
	this->value = value;
}