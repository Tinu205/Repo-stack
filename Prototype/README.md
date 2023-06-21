# Repo stack
This is a concept we have selected for evision a kind of hackathon for freshers in our college
This is a simple prototype of a patient record management system implemented in C. The program allows users to add patient information, read patient data, and exit the system. It includes a basic login system to ensure authorized access to the system.

# Features
The program provides the following features:

## Login System: 
Users are required to enter a username and password to access the system. The default username is "Panda" and the default password is "Who-cares". The login credentials can be modified by changing the values of the usr and pass variables in the check_pass() function.

## Add Patient:
Users can add patient information, including name, ID, age, doctor's name, and medical history. The patient data is stored in a binary file named "patient_record.bin". The program checks if a patient with the same ID already exists before adding a new patient.

## Read Patient Data: 
Users can search for and read patient data by entering the patient's name and ID. The program reads the patient records from the "patient_record.bin" file and displays the matching patient's information.

## Exit:
Users can choose to exit the system, which will terminate the program.

Usage
Compilation: Compile the C program using a C compiler, such as GCC, with the following command:

Copy code
gcc patient_record.c -o patient_record
Execution: Run the compiled program using the following command:

bash
Copy code
./patient_record
Login: Enter the username and password when prompted. The default username is "Panda" and the default password is "Who-cares".

Main Menu: After successful login, the program will display a menu with the following options:

Add patient: Enter option 1 to add patient information. Follow the prompts to enter the patient's details.
Read data: Enter option 3 to search for and read patient data. Enter the patient's name and ID when prompted.
Exit: Enter any other number to exit the program.
File Storage
The patient data is stored in a binary file named "patient_record.bin". Each patient's information is stored as a structure of type hooman defined in the program. The structure contains the following fields:

name: A character array to store the patient's name.
id: An integer to store the patient's ID.
age: An integer to store the patient's age.
Doctors: A character array to store the names of the doctor(s) treating the patient.
Medic_hist: A character array to store the patient's medical history.
When adding a new patient, the program checks if the provided ID already exists in the file to avoid duplications.

Limitations and Future Improvements
The program does not include options to edit or delete existing patient records. These features can be added in future versions of the program.
Error handling and validation of user input are minimal. Additional checks can be implemented to ensure the correctness of entered data.
The program uses a binary file to store patient records, which can make it difficult to modify or view the data directly. Consider using a more accessible and structured format, such as a text-based database or CSV file, for easier manipulation and analysis of patient records.
Feel free to customize and improve the program according to your needs.




