#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 1000
#define vmax 100000

//defining the struct
typedef struct {
    char name[max];
    int id;
    int age;
    char Doctors[max];
    char Medic_hist[vmax];
} hooman;

//Adding the patient
void add_pat() {
    hooman panda;
    FILE* fp;
    fp = fopen("patient_record.bin", "ab");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter name of the patient: ");
    scanf("%s", panda.name);

    printf("Enter id of the patient: ");
    scanf("%d", &panda.id);

    printf("Enter age of the patient: ");
    scanf("%d", &panda.age);

    printf("Enter the Doctor name separated by space: ");
    scanf(" %[^\n]", panda.Doctors);

    printf("Enter the medical history separated by spaces: ");
    scanf(" %[^\n]", panda.Medic_hist);

    // Check if patient ID already exists
    hooman temp;
    fseek(fp, 0, SEEK_SET);
    while (fread(&temp, sizeof(hooman), 1, fp) == 1) {
        if (temp.id == panda.id) {
            printf("Patient with ID %d already exists.\n", panda.id);
            fclose(fp);
            return;
        }
    }

    fwrite(&panda, sizeof(hooman), 1, fp);
    fclose(fp);
}

//Reads the patient data
void read_dat() {
    system("clear");
    FILE* fp;
    fp = fopen("patient_record.bin", "rb");

    char name[max];
    int id;

    printf("Enter the name of the patient: \n");
    scanf(" %[^\n]", name);

    printf("Enter the id: ");
    scanf("%d", &id);

    hooman panda;
    // reads the file
    while (fread(&panda, sizeof(hooman), 1, fp) == 1) {
        if ((strcmp(panda.name, name) == 0) && (panda.id == id)) {
            printf("Name: %s\n", panda.name);
            printf("Id: %d\n", panda.id);
            printf("Age: %d\n", panda.age);
            printf("Doctors: %s\n", panda.Doctors);
            printf("Medical History: %s\n", panda.Medic_hist);
            printf("\n");
        }
        else if(strcmp(panda.name,name) != 0){
            printf("Not found");
        }
    }
    fclose(fp);
}


//Edits the patient data
void edit_pat(){

    char name[max];
    int id;
    FILE* fp;

    scanf(" %[^\n]",name);
    scanf("%d",&id);

    fp = fopen("patient_record.bin","rb+");

}

int main() {
    int valid = system("./password");

    system("clear");
    if (valid == 0) {
        printf("Invalid password/username\n");
        system("./password");
    }
    else {
        printf("Login successful \n");

        while (1) {
            printf("Choose an option\n");
            printf("1) Add patient\n2) Edit existing patient\n3) Read data\n4) Exit\n");
            int choice;
            scanf("%d",&choice);

            switch (choice) {
                case 1:
                    system("clear");
                    add_pat();
                    break;
                case 3:
                    system("clear");
                    read_dat();
                    break;
                default:
                    break;
            }
            if (choice == 4) {
                break;
            }
        }
    }
    return 0;
}
