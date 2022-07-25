//Vaccine Inventory Management System [ICP Assignment]
//Marcell Agung Wahyudi / TP058650
#include "main.h"
#include "functions.h"

int main(){
    printf("Vaccine Inventory Management System created by Macel\n----------------------------------------------------");
    int userinput;
    while(1){
        puts("\nWelcome to Main Menu");
        puts("Select a Function :\n1. Create New Inventory\n2. Update Vaccine Quantity\n3. Search Vaccine\n4. View List of all Vaccines and their Distributed Quantities\n5. Exit Program\n");
        scanf("%d", &userinput);
        getchar();
        while(userinput>5 || userinput<1){   /*Code to verify*/
            puts("Invalid Input, Please Select a Function: \n1. Create New Inventory\n2. Update Vaccine Quantity\n3. Search Vaccine\n4. View List of all Vaccines and their Distributed Quantities\n5. Exit Program\n");
            scanf("%d", &userinput);
            getchar();
        }
        switch(userinput){
            case 1:
                createInventory();
                break;
            case 2:
                updateVaccineQnty();
                break;
            case 3:
                searchVaccine();
                break;
            case 4:
                viewVacDist();
                break;
            case 5:
                printf("\n---------------\nExiting Program\n"); //Additional Things*
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}
