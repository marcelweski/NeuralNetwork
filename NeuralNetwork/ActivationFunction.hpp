#pragma once

namespace NeuralNetwork
{
	class ActivationFunction
	{
	public:
		virtual double activate(double input) = 0;
	};

	class Identity : public ActivationFunction
	{
	public:
		virtual double activate(double input)
		{
			return input;
		}
	};

	class Boolean : public ActivationFunction
	{
	public:
		virtual double activate(double input)
		{
			if (input < 0.0)
				return 0.0;
			return 1.0;
		}
	};

	class Sigmoid : public ActivationFunction
	{
	public:
		virtual double activate(double input)
		{
			return 1.0 / (1.0 + pow(exp(1.0), -input));
		}
	};

	class HyperbolicTangent : public ActivationFunction
	{
	public:
		virtual double activate(double input)
		{
			double epx = pow(exp(1.0), input);
			double enx = pow(exp(1.0), -input);

			return (epx - enx) / (epx + enx);
		}
	};
}