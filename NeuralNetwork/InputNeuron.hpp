#pragma once
#include "Neuron.hpp"

namespace NeuralNetwork
{
	class InputNeuron : public Neuron
	{
	private:
		double value;

	public:
		InputNeuron();

		virtual double getValue();
		void setValue(double value);
	};
}