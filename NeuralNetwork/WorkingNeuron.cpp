#include "WorkingNeuron.hpp"

void NeuralNetwork::WorkingNeuron::addConnection(Connection* connection)
{
	this->connections.push_back(connection);
}
void NeuralNetwork::WorkingNeuron::setActivationFunction(ActivationFunction* activationFunction)
{
	this->activationFunction = activationFunction;
}

NeuralNetwork::WorkingNeuron::WorkingNeuron(ActivationFunction* activationFunction)
{
	this->setActivationFunction(activationFunction);
}
NeuralNetwork::WorkingNeuron::~WorkingNeuron()
{
	for (Connection* connection : this->connections)
	{
		delete connection;
	}
	this->connections.clear();
}

double NeuralNetwork::WorkingNeuron::getValue()
{
	double sum = 0.0;
	for (Connection* connection : this->connections)
	{
		sum += connection->getValue();
	}
	return this->activationFunction->activate(sum);
}
