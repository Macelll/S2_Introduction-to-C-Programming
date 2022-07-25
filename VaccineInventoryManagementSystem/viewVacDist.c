#include "main.h"
#include "functions.h"
#include "swapFloat.h"
#include "countLines.h"
/*4. Produce a list of vaccines and their distributed quantities*/
void viewVacDist(){

    FILE* disttxt;
    FILE* vactxt;
    int i, j, count, vaccount;
    char temp[4];

    //Function is to count how many lines in dist.txt, to determine the size for dist struct in order to save memory;
    count = countLines("dist.txt");
    struct Distributed dist[count];
    struct distinfo dinfo[count];

    vaccount = countLines("vaccine.txt");
    struct Vaccine vac[vaccount];

    printf("Viewing List of all Vaccines and their Distributed Quantities\n-------------------------------------------------------------\n");
    disttxt = fopen("dist.txt", "r");
    vactxt = fopen("vaccine.txt", "r");
    for(i=0; i<vaccount; i++){
        fscanf(vactxt,"%s %s %s %d %f %f", vac[i].name, vac[i].code, vac[i].country, &vac[i].dosage, &vac[i].population, &vac[i].quantity);
    }
    for(i=0; i<count; i++){
        fscanf(disttxt,"%s %s %f", dist[i].code, dist[i].status, &dist[i].quantity);
    }
    for(i=0; i<vaccount; i++){
        strcpy(dinfo[i].code, vac[i].code);
        for(j=0; j<count; j++){
            if(strcmp(dist[j].code, vac[i].code)==0 && strcmp(dist[j].status, "Distributed")== 0){  /*strcmp if same it will return 0*/
                dinfo[i].quantity+=dist[j].quantity;
            }
        }
    }
    for(i=0; i<vaccount; i++){                 /*Code to Bubble Sort Descendingly(From Highest to Lowest)*/
        for(j=0; j<vaccount-i-1; j++){
            if (dinfo[j].quantity < dinfo[j+1].quantity){
                swapFloat(&dinfo[j].quantity, &dinfo[j+1].quantity);
                strcpy(temp, dinfo[j].code);   /*Line 61-63, to Swap Strings*/
                strcpy(dinfo[j].code, dinfo[j+1].code);
                strcpy(dinfo[j+1].code, temp);
            }
        }
    }
    printf("Listing Vaccine code with Distributed Value Descendingly (From Highest Quantity to Lowest) : \n");
    for(i=0; i<vaccount; i++){
        printf("(%s) Total Distributed : %.2f Million\n", dinfo[i].code, dinfo[i].quantity);
    }
    printf("\nReturning to Main Menu...\n");
    return 69;
}
