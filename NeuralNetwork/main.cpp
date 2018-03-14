#include <iostream>
#include "NeuralNetwork.hpp"

bool getFitness(double input1, double input2, double output)
{
	return (
		(input1 == 0.0 && input2 == 0.0 && output <  0.5) ||
		(input1 == 0.0 && input2 == 1.0 && output >= 0.5) ||
		(input1 == 1.0 && input2 == 0.0 && output >= 0.5) ||
		(input1 == 1.0 && input2 == 1.0 && output <  0.5)
	);
}

int main()
{
	NeuralNetwork::NeuralNetwork nn(new NeuralNetwork::Sigmoid);

	NeuralNetwork::InputNeuron* input1 = nn.createInputNeuron();
	NeuralNetwork::InputNeuron* input2 = nn.createInputNeuron();

	NeuralNetwork::WorkingNeuron* output = nn.createOutputNeuron();

	nn.createMesh();

	input1->setValue(0);
	input2->setValue(1);

	double i1 = input1->getValue();
	double i2 = input2->getValue();

	double o = output->getValue();
	bool rightAnswer = getFitness(i1, i2, o);

	printf("Output: %.5f - Right answer: %s\n", o, rightAnswer ? "yes" : "no");
	

	system("pause");
	return 0;
}