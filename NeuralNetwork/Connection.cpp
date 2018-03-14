#include "Connection.hpp"

NeuralNetwork::Connection::Connection(Neuron* neuron, double weight)
{
	this->neuron = neuron;
	this->weight = weight;
}

double NeuralNetwork::Connection::getValue()
{
	return this->neuron->getValue() * this->weight;
}