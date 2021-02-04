#pragma once
#include <vector>
#include <string>
#include <math.h>

#include "Synapse.h"

// all neurons
class INeuron {
protected:
	// neuron values
	double bias;

	// input-output synapses
	std::vector<ISynapse*> synInput;
	std::vector<ISynapse*> synOutput;

	// activation function
	virtual double activation(double x) = 0;	// I

public:
	// constructor
	INeuron(double toSetBias);

	// edit input-output synapses
	void addInputSyn(ISynapse *toAdd);
	void addOutputSyn(ISynapse *toAdd);

	// make neuron work
	void activateNeuron();
};



// linear activation neuron
class LinearNeuron : public INeuron {
protected:
	// activation function
	double activation(double x);

public:
	// constructor
	LinearNeuron(double x);
};



// sigmoid activation neuron
class SigmoidNeuron : public INeuron {
protected:
	// activation function
	double activation(double x);

public:
	// constructor
	SigmoidNeuron(double x);
};



// tanh activation neuron
class TanhNeuron : public INeuron {
protected:
	// activation function
	double activation(double x);

public:
	// constructor
	TanhNeuron(double x);
};