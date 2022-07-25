#include "main.h"

/*1. Inventory Creation*/
void createInventory(){
    int DosRqrd, confirm=69;
    char NmOfVac[30], VacCode[4], ProdCntr[30];
    float PopCover, VacQnty;
    FILE* vactxt = fopen("vaccine.txt", "a");
    //Confirmation Code;
    do{
        printf("\nCreating New Vaccine Inventory, Enter 1 to Continue, or 0 to go Back : ");
        scanf("%d", &confirm);
        getchar();
        if (confirm==0){
            return 69;
        }
    }while(confirm!=1);
    //Code to append new vaccine details to vaccine.txt;
    do{
        printf("Enter Name of Vaccine      : "); gets(NmOfVac);
        printf("Enter Vaccine Code         : "); gets(VacCode);
        printf("Enter Producing Country    : "); gets(ProdCntr);
        printf("Dosage Required            : "); scanf("%d", &DosRqrd); getchar();//Getchar so if the user accidentally input char, it won't interrupt the code
        printf("Population Covered         : "); scanf("%f", &PopCover); getchar();
        printf("Vaccine Quantity (In Mill) : "); scanf("%f", &VacQnty); getchar();
        confirm=69;
        printf("\nEnter 2 to Save and Create another inventory, 1 to Save and go back to Main Menu, \n0 to Discard and go back to Main Menu, or Any Number to Redo\n");
        scanf("%d", &confirm);
        getchar();
        if(confirm==0){
            fclose(vactxt);
            return 69;
        }
        else if(confirm==1 || confirm==2){  /*if confirm equal to 1, the while loop will stop and user will be returned to menu*/
            printf("\nVaccine Details Successfully Saved\n");
            fprintf(vactxt, "%s %s %s %d %.1f %.1f\n", NmOfVac, VacCode, ProdCntr, DosRqrd, PopCover, VacQnty);
        }
    }while(confirm!=1);
    fclose(vactxt); //Close File;
    printf("\nReturning to Main Menu...\n");
    return 69;
}
