#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Vaccine{
    char name[30];
    char code[4];
    char country[30];
    int dosage;
    float population;
    float quantity;
};
struct Distributed{
    char code[4];
    char status[12];
    float quantity;
};
struct distinfo{
    char code[4];
    float quantity;
};
void createInventory();
void updateVaccineQnty();
void searchVaccine();
void viewVacDist();

#endif // FUNCTIONS_H
