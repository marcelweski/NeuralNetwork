#pragma once
#include <vector>
#include "Neuron.hpp"
#include "Connection.hpp"
#include "ActivationFunction.hpp"

namespace NeuralNetwork
{
	class WorkingNeuron : public Neuron
	{
		friend class NeuralNetwork;
	private:
		std::vector<Connection*> connections;
		ActivationFunction* activationFunction;

		void addConnection(Connection* connection);
		void setActivationFunction(ActivationFunction* activationFunction);

	public:
		WorkingNeuron(ActivationFunction* activationFunction);
		~WorkingNeuron();

		virtual double getValue();
	};
}
