#pragma once
#include "citizen.h"
#include <fstream>

#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>

using namespace std;
class Citizen;


class County {

private:
    char* name;
    int id;
    bool is_relative;
    int number_of_electors;
    int current_vote_amount;
    Citizen** residents;
    int residents_num_size;
    int residents_num_logi;
    Citizen** chosen_electors;
    int chosen_electors_size;
    int chosen_electors_logi;
    void resizeResidents();
    void resizeChosenElectors();

public:
    static int num_of_counties;
    /* Counstructors and destructors */
    County(char* _name, int _number_of_electors, bool _is_relative);
    County();
   
    ~County();
    /* Getters */
    char* getName() const { return name; }
    int getId() const { return id; }
    bool isRelative() const { return is_relative; }
    int getVoteAmount() const { return current_vote_amount; }
    int getNumberOfElectors() const { return number_of_electors; }
    Citizen** getResidents() const { return residents; }
    int residentsLen() const { return residents_num_logi; }
    Citizen** getChosenElectors() const { return chosen_electors; }
    int chosenElectorsLen() const { return chosen_electors_logi; }
    /* Setter */
    bool setChosenElectorsLen(int new_len) { chosen_electors_logi = new_len; return true; }
    /* Adders */
    bool addVote();
    bool addResident(Citizen* new_resident);
    bool addChosenElector(Citizen* chosen_elector);
    /* Operator overloads */
    friend ostream& operator<<(ostream& os, const County& county);

    /*Serialization*/

    void save(ostream& out) const;
    void load(istream& in);
};