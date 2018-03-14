#include <iostream>
#include "NeuralNetwork.hpp"

int main()
{
	NeuralNetwork::NeuralNetwork nn(new NeuralNetwork::Sigmoid);

	NeuralNetwork::InputNeuron* input1 = nn.createInputNeuron();
	NeuralNetwork::InputNeuron* input2 = nn.createInputNeuron();

	NeuralNetwork::WorkingNeuron* output = nn.createOutputNeuron();

	nn.createMesh();

	input1->setValue(0);
	input2->setValue(1);

	double o = output->getValue();

	printf("Output: %.5f\n", o);

	system("pause");
	return 0;
}