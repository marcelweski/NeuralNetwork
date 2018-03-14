#pragma once
#include "Neuron.hpp"

namespace NeuralNetwork
{
	class Connection
	{
		friend class NeuralNetwork;
	private:
		Neuron* neuron;
		double weight;

	public:
		Connection(Neuron* neuron, double weight);

		double getValue();
	};
}