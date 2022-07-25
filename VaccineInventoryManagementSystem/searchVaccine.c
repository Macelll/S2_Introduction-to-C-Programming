#include "main.h"
#include "functions.h"
#include "countLines.h"
/*3. Search vaccine and its available quantity by using vaccine code*/
void searchVaccine(){

    char userinput[4];
    int confirm, i, counter, count;
    FILE* vactxt;

    count = countLines("vaccine.txt");
    struct Vaccine vac[count];

    printf("\nSearch Vaccine Quantity by Vaccine Code\n----------------------------------------\n");
    do{printf("Enter 1 to Continue, or 0 to go back to Main Menu : ");
    scanf("%d", &confirm);
    getchar();
        if(confirm==0){
            return 69;}
    }while(confirm!=1);

    vactxt = fopen("vaccine.txt", "r");
    printf("Enter Vaccine Code : ");


    while(confirm==1){
        scanf("%s", userinput);
        for(i=0; i<count; i++){
            fscanf(vactxt,"%s %s %s %d %f %f", vac[i].name, vac[i].code, vac[i].country, &vac[i].dosage, &vac[i].population, &vac[i].quantity);
            if (strcmp(userinput, vac[i].code)==0){   /*strcmp userinput with vac[i].code, if it's the same, it will return 0, else it will return 1*/
                confirm=0;
                break;
            }
            else if (i == count-1){        /*The for loop is i<count, so if i reaches count-1 which means the final loop, it will then execute this code*/
                printf("Vaccine Code not Found, Please Enter Again : ");
                fclose(vactxt);
            }
        }
    }
    //This code will only be executed if strcmp(userinput, vac[i].code == 0, else it won't be executed.
    printf("\n*Vaccine Found*\n\nDisplaying Vaccine Details : \n");
    printf("Vaccine Name : %s\n", vac[i].name);
    printf("Vaccine Code : %s\n", vac[i].code);
    printf("Vaccine Country : %s\n", vac[i].country);
    printf("Vaccine Dosage Needed : %d\n", vac[i].dosage);
    printf("Vaccine Population Coverage : %.1f\n", vac[i].population);
    printf("Vaccine Quantity (In Mill) : %.1f\n", vac[i].quantity);
    printf("\nReturning to Main Menu...\n");
    fclose(vactxt);
    return 69;
}
