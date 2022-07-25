#include "main.h"
#include "functions.h"
#include "countLines.h"
/*2. Update Vaccine Quantities*/
void updateVaccineQnty(){

    int i, confirm, count ,counter = 1;
    char userinput[4];
    float qntyinput;
    FILE* vactxt;
    FILE* disttxt;

    count = countLines("vaccine.txt");
    struct Vaccine vac[count];

    printf("\nUpdating Vaccine Quantity\n-------------------------\n");
    do{printf("Enter 1 to Continue, or 0 to go back to Main Menu : ");
    scanf("%d", &confirm);
    getchar();
        if(confirm==0){
            return 69;}
    }while(confirm!=1);

    puts("\nListing Vaccine Names with each Codes and Quantities (In Mill) :");
    vactxt = fopen("vaccine.txt", "r");
    for(i=0; i<count; i++){
        fscanf(vactxt,"%s %s %s %d %f %f", vac[i].name, vac[i].code, vac[i].country, &vac[i].dosage, &vac[i].population, &vac[i].quantity);
        printf("%s = %s, %.2f\n", vac[i].name, vac[i].code, vac[i].quantity);
    }
    fclose(vactxt);

    //Code to find the specific Vaccine Code;
    printf("\nSelect a Vaccine code and modify the quantity : ");
    while(counter==1){
    scanf("%s", userinput);
        for(i=0; i<count; i++){
            if (strcmp(userinput, vac[i].code)==0){
                counter=0;
                break;
            }
            else if (i == count-1){
                printf("Vaccine Code not Found, Please Enter Again : ");
            }
        }
    }
    //Code to Add or Subtract Vaccine Quantity;
    printf("%s, Quantity : %.2f\n", vac[i].name, vac[i].quantity);
    printf("Enter 1 to Add Quantity, or 0 to Distribute Quantity : ");
    scanf("%d", &confirm);
    getchar();
    //Code to Add Vaccine Quantity;
    if(confirm==1){
        printf("Quantity to be Added (In Million) : ");
        scanf("%f", &qntyinput);
        vac[i].quantity+=qntyinput;
        printf("\nSuccessfully Updated Vaccine Quantity\nUpdate Vaccine Details : \n");
        printf("%s, = %s %.2f\n", vac[i].name, vac[i].code, vac[i].quantity);
        vactxt = fopen("vaccine.txt", "w");
        disttxt = fopen("dist.txt", "a");
        fprintf(disttxt, "%s Added %.2f\n", vac[i].code, qntyinput);
        for(i=0; i<count; i++){
            fprintf(vactxt,"%s %s %s %d %.2f %.2f\n", vac[i].name, vac[i].code, vac[i].country, vac[i].dosage, vac[i].population, vac[i].quantity);
        }
        fclose(vactxt);
        fclose(disttxt);
    }
    //Code to Subtract/Distribute Vaccine Quantity;
    else if(confirm==0){
        printf("Quantity to be Distributed (In Million) : ");
        scanf("%f", &qntyinput);
        vac[i].quantity-=qntyinput;
        while(vac[i].quantity<0){
            printf("\nNot Enough Vaccine to be Distributed");
            vac[i].quantity+=qntyinput;
            printf("\nPlease Re-Enter Distributed Quantity (In Millions) : ");
            scanf("%f", &qntyinput);
            vac[i].quantity-=qntyinput;
        }
        printf("\nSuccessfully Updated Vaccine Quantity\nUpdate Vaccine Details : \n");
        printf("%s = %s, %.2f\n", vac[i].name, vac[i].code, vac[i].quantity);
        vactxt = fopen("vaccine.txt", "w");
        disttxt = fopen("dist.txt", "a");
        fprintf(disttxt, "%s Distributed %.2f\n", vac[i].code, qntyinput);
        for(i=0; i<count; i++){
            fprintf(vactxt,"%s %s %s %d %.2f %.2f\n", vac[i].name, vac[i].code, vac[i].country, vac[i].dosage, vac[i].population, vac[i].quantity);
        }
        fclose(vactxt);
        fclose(disttxt);
    }
    else{
        printf("Invalid Input, Returning to Main Menu");
        return 69;
    }
    puts("\nReturning to Main Menu");
    return 69;
}

//    //Code to replace old Vaccine Quantity for a new Quantity (Incase it's needed);
//    printf("%s, Quantity : %.2f\n", vac[i].name, vac[i].quantity);
//    printf("Enter your new quantity value : ");
//    scanf("%f", &qntyinput);
//    vac[i].quantity =  qntyinput;
//    fclose(vactxt);
//    vactxt = fopen("vaccine.txt", "w");
//    for(i=0; i<5; i++){
//        fprintf(vactxt,"%s %s %s %d %.1f %.1f\n", vac[i].name, vac[i].code, vac[i].country, vac[i].dosage, vac[i].population, vac[i].quantity);
//    }
//    fclose(vactxt);
//    printf("\nSuccessfully Updated Vaccine Quantity, Returning to Main Menu\n");
//    return 69;
//}
