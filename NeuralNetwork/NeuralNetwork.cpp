#include "NeuralNetwork.hpp"

void NeuralNetwork::NeuralNetwork::createHiddenNeurons()
{
	// create hidden neurons
	for (int i = 0; i < this->inputNeurons.size() + this->outputNeurons.size(); i++)
	{
		this->hiddenNeurons.push_back(new WorkingNeuron(this->activationFunction));
	}
}

NeuralNetwork::NeuralNetwork::NeuralNetwork(ActivationFunction* activationFunction)
{
	this->setActivationFunction(activationFunction);
	srand((unsigned int)time(nullptr));
}

NeuralNetwork::NeuralNetwork::~NeuralNetwork()
{
	this->clear();
	delete this->activationFunction;
}

void NeuralNetwork::NeuralNetwork::setActivationFunction(ActivationFunction* activationFunction)
{
	this->activationFunction = activationFunction;
	
	// apply new activation function to hidden neurons
	for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
	{
		hiddenNeuron->setActivationFunction(this->activationFunction);
	}

	// apply new activation function to output neurons
	for (WorkingNeuron* outputNeuron : this->outputNeurons)
	{
		outputNeuron->setActivationFunction(this->activationFunction);
	}
}

NeuralNetwork::InputNeuron* NeuralNetwork::NeuralNetwork::createInputNeuron()
{
	this->inputNeurons.push_back(new InputNeuron());
	return this->inputNeurons.back();
}

NeuralNetwork::WorkingNeuron* NeuralNetwork::NeuralNetwork::createOutputNeuron()
{
	this->outputNeurons.push_back(new WorkingNeuron(this->activationFunction));
	return this->outputNeurons.back();;
}

void NeuralNetwork::NeuralNetwork::createMesh()
{
	this->createHiddenNeurons();

	// connect hidden neurons with input neurons
	for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
	{
		for (InputNeuron* inputNeuron : this->inputNeurons)
		{
			hiddenNeuron->addConnection(new Connection(inputNeuron, random(-1, 1)));
		}
	}

	// connect output neurons with hidden neurons
	for (WorkingNeuron* outputNeuron : this->outputNeurons)
	{
		for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
		{
			outputNeuron->addConnection(new Connection(hiddenNeuron, random(-1, 1)));
		}
	}
}
void NeuralNetwork::NeuralNetwork::createMesh(const std::vector<double>& weights)
{
	assert(weights.size() == (this->inputNeurons.size() * this->hiddenNeurons.size()) * (this->hiddenNeurons.size() * this->outputNeurons.size()));

	this->createHiddenNeurons();

	uint64_t weightIdx = 0;

	// connect hidden neurons with input neurons
	for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
	{
		for (InputNeuron* inputNeuron : this->inputNeurons)
		{
			hiddenNeuron->addConnection(new Connection(inputNeuron, weights[weightIdx++]));
		}
	}

	// connect output neurons with hidden neurons
	for (WorkingNeuron* outputNeuron : this->outputNeurons)
	{
		for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
		{
			outputNeuron->addConnection(new Connection(hiddenNeuron, weights[weightIdx++]));
		}
	}
}

void NeuralNetwork::NeuralNetwork::clear()
{
	// clear inputs neurons
	for (InputNeuron* inputNeuron : this->inputNeurons)
	{
		delete inputNeuron;
	}
	this->inputNeurons.clear();

	// clear hidden neurons
	for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
	{
		delete hiddenNeuron;
	}
	this->hiddenNeurons.clear();

	// clear output neurons
	for (WorkingNeuron* outputNeuron : this->outputNeurons)
	{
		delete outputNeuron;
	}
	this->outputNeurons.clear();
}

std::vector<double> NeuralNetwork::NeuralNetwork::getWeights()
{
	std::vector<double> weights;

	// connect hidden neurons with input neurons
	for (WorkingNeuron* hiddenNeuron : this->hiddenNeurons)
	{
		for (Connection* connection : hiddenNeuron->connections)
		{
			weights.push_back(connection->weight);
		}
	}

	// connect output neurons with hidden neurons
	for (WorkingNeuron* outputNeuron : this->outputNeurons)
	{
		for (Connection* connection : outputNeuron->connections)
		{
			weights.push_back(connection->weight);
		}
	}

	return weights;
}
