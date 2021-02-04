#pragma once

// all synapses
class ISynapse {
protected:
	// synapse data
	double value;
	double weight;

public:
	// constructors
	ISynapse(double weight = 0);

	// push-pull data functions
	void pushValue(double toSetValue);
	virtual double pullValue() = 0;			// I
};



// default synapse
class Synapse : public ISynapse {
public:
	// constructor
	Synapse(double weight = 0);

	// pull value (as default)
	double pullValue();
};



// IO synapse (no weight)
class IOSynapse : public ISynapse {
public:
	// constructor
	IOSynapse();

	// pull value (without weight)
	double pullValue();
};