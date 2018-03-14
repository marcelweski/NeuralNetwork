#pragma once
#include <vector>
#include <ctime>
#include <cassert>
#include "InputNeuron.hpp"
#include "WorkingNeuron.hpp"
#include "ActivationFunction.hpp"

namespace NeuralNetwork
{
	class NeuralNetwork
	{
	private:
		ActivationFunction* activationFunction;
		std::vector<InputNeuron> inputNeurons;
		std::vector<WorkingNeuron> hiddenNeurons;
		std::vector<WorkingNeuron> outputNeurons;

		void createHiddenNeurons();

	public:
		NeuralNetwork(ActivationFunction* activationFunction);
		~NeuralNetwork();

		void setActivationFunction(ActivationFunction* activationFunction);

		InputNeuron* createInputNeuron();
		WorkingNeuron* createOutputNeuron();

		void createMesh();
		void createMesh(const std::vector<double>& weights);

		std::vector<double> getWeights();
	};
}
