#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 1000
#define vmax 100000

typedef struct {
        char name[max];
        int id;
        int age;
        char Doctors[max];
        char Medic_hist[vmax];
}hooman;//dummy info data struc

void add_pat(){
    
    hooman panda;
    FILE *fp;
    fp = fopen("patient_record.bin","ab");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter name of the patient: ");
    scanf("%s",panda.name);

    printf("Enter id of the patient: ");
    scanf("%d",&panda.id);

    printf("Enter age of the patient: ");
    scanf("%d",&panda.age);

    printf("Enter the Doctor name seperated by space: ");
    scanf(" %[^\n]",panda.Doctors);

    printf("Enter the medical history seperated by spaces: ");
    scanf(" %[^\n]",panda.Medic_hist);

    fprintf(fp, "%s %d %d %s %s\n", panda.name, panda.id, panda.age, panda.Doctors, panda.Medic_hist);

    fwrite(&panda, sizeof(hooman), 1, fp);
    fclose(fp);
    
}
//work here tomorrow !!
void read_dat(){
    system("clear");
    FILE *fp;
    fp = fopen("patient_record.bin","rb");
    
    char name[max];
    int id;

    printf("Enter the name of the patient: \n");
    scanf(" %[^\n]",name);

    printf("Enter the id: ");
    scanf("%d",&id);

    hooman panda;
    //reads the file
    while (fread(&panda, sizeof(hooman), 1, fp) == 1) {
        if ((strcmp(panda.name,name) == 0) && (panda.id==id)) {
            // Match found, process the struct data
            printf("Name: %s\n", panda.name);
            printf("Age: %d\n", panda.age);
            printf("Id: %d\n", panda.id);
            printf("\n");
        }
    }
    fclose(fp);

}
int main(){
    
    int valid = system("./password");
        
    while(1)//checks login credentials
    {
        system("clear");
        if(valid != 0){
            printf("Login successful \n");
            break;
        }else{
            printf("Invalid password/username\n");
            system("./password");
        }
    }
    while(1)//Actions
    {
        system("clear");
        printf("Choose an option\n");
        printf("1)Add patient\n2)Edit existing patient\n3)Read data\n4)Exit\n");
        int choise;
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
            system("clear");
            add_pat();
            break;
        case 3:
            system("clear");
            read_dat();
        default:
            break;
        }
        if(choise == 4){
            break;
        }
    }
}