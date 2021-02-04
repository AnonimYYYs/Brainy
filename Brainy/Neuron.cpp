#include "Neuron.h"

INeuron::INeuron(double toSetBias)
{
	bias = toSetBias;
	synInput = std::vector<ISynapse*>();
	synOutput = std::vector<ISynapse*>();
}

void INeuron::addInputSyn(ISynapse * toAdd)
{
	synInput.push_back(toAdd);
}

void INeuron::addOutputSyn(ISynapse * toAdd)
{
	synOutput.push_back(toAdd);
}

void INeuron::activateNeuron()
{
	double summ = 0;
	for (int i = 0; i < synInput.size(); i++) {
		summ += synInput[i]->pullValue();
	}
	double res = activation(summ);
	for (int i = 0; i < synOutput.size(); i++) {
		synOutput[i]->pushValue(res);
	}
}

double LinearNeuron::activation(double x)
{
	return x;
}

LinearNeuron::LinearNeuron(double x) : INeuron(x)
{
}

double TanhNeuron::activation(double x)
{
	return (exp(2 * x) - 1) / (exp(2 * x) + 1);
}

TanhNeuron::TanhNeuron(double x) : INeuron(x)
{
}

double SigmoidNeuron::activation(double x)
{
	return 1 / (1 + exp(-x));
}

SigmoidNeuron::SigmoidNeuron(double x) : INeuron(x)
{
}
