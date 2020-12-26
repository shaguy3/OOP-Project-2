#include "complex_cycle.h"

ComplexCycle::ComplexCycle(Date& _date_of_election) :
	ElectionCycle(_date_of_election),
	counties_num_size(5),
	counties_num_logi(0)
{
	counties = new County * [counties_num_size];
}

ComplexCycle::~ComplexCycle() {
	delete[] counties;
}

void ComplexCycle::resizeCounties() {
    counties_num_size *= 2;
    County** new_arr = new County * [counties_num_size];

    for (int i = 0; i < counties_num_logi; i++) {
        new_arr[i] = counties[i];
    }

    counties = new_arr;
}

bool ComplexCycle::addCounty(County* county) {
    if (counties_num_logi == counties_num_size) { resizeCounties(); }

    counties[counties_num_logi] = county;
    counties_num_logi++;

    return true;
}

ostream& operator<<(ostream& os, ComplexCycle& election_cycle) {
    os << "Election cycle of date: " << election_cycle.getDate() << endl \
        << "Residents: " << endl;

    for (int i = 0; i < election_cycle.residentslen(); i++) {
        os << *election_cycle.getResidents()[i] << endl;
    }

    os << endl << "Counties: " << endl;

    for (int i = 0; i < election_cycle.countieslen(); i++) {
        os << *election_cycle.getCounties()[i] << endl;
    }

    os << endl << "Parties: " << endl;

    for (int i = 0; i < election_cycle.partieslen(); i++) {
        os << *election_cycle.getParties()[i] << endl;
    }

    return os;
}