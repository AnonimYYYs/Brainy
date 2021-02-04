#include<iostream>
#include"Neuron.h"


using namespace std;




int main() {

	INeuron *n1 = new LinearNeuron(0.3);
	INeuron *n2 = new SigmoidNeuron(0.2);
	ISynapse *inSyn = new IOSynapse();
	ISynapse *outSyn = new IOSynapse();
	ISynapse *hidden = new Synapse(-0.7);
	n1->addInputSyn(inSyn);
	n1->addOutputSyn(hidden);
	n2->addInputSyn(hidden);
	n2->addOutputSyn(outSyn);
	inSyn->pushValue(1.0);
	n1->activateNeuron();
	n2->activateNeuron();
	cout << outSyn->pullValue() << endl;

	system("pause");
	return(0);
}