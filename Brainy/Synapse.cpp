#include "Synapse.h"

ISynapse::ISynapse(double weight) : value(0), weight(weight)
{
}

void ISynapse::pushValue(double toSetValue)
{
	value = toSetValue;
}

Synapse::Synapse(double weight) : ISynapse(weight)
{
}

double Synapse::pullValue()
{
	return value * weight;
}

IOSynapse::IOSynapse() : ISynapse()
{
}

double IOSynapse::pullValue()
{
	return value;
}
