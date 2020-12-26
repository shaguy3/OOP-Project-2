#include "simple_cycle.h"

SimpleCycle::SimpleCycle(Date& _date_of_election, int number_of_electors) :
	ElectionCycle(_date_of_election), number_of_electors(number_of_electors),
	chosen_electors_logi(0), chosen_electors_size(5)
{
	chosen_electors = new Citizen * [chosen_electors_size];
}

SimpleCycle::~SimpleCycle() {
	delete[] chosen_electors;
}

void SimpleCycle::resizeChosenElectors() {
	chosen_electors_size *= 2;
	Citizen** new_arr = new Citizen * [chosen_electors_size];

	for (int i = 0; i < chosen_electors_logi; i++) {
		new_arr[i] = chosen_electors[i];
	}

	chosen_electors = new_arr;
}

bool SimpleCycle::addChosenElector(Citizen* chosen_elector) {
	if (chosen_electors_logi == chosen_electors_size) { resizeChosenElectors(); }

	chosen_electors[chosen_electors_logi] = chosen_elector;
	chosen_electors_logi++;

	return true;
}