#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"
#define TRUE 1
#define FIRST_LINE 500
#define LAST_LINE 1000

void readmy_CSV(Person *people)
{
    int j = 1;
    FILE *myFile;
    myFile = fopen("People.csv", "r");

    if (myFile == NULL)
    {
        printf("File did not successfully open. \n");
    }

    rewind(myFile);

    char myLine[200];
    fgets(myLine, 1024, myFile);
    char *delimiter = ",";

    int i = 0;

    for (char c = getc(myFile); c != EOF; c = getc(myFile))
    {
        if (c == '\n')
        {
            j++;
        }
    }

    people[j + 1];
    rewind(myFile);

    while (fgets(myLine, 200, (FILE *)myFile) != NULL)
    {

        people[i].id = atoi(strtok(myLine, delimiter));

        strcpy(people[i].firstname, strtok(NULL, delimiter));

        strcpy(people[i].lastname, strtok(NULL, delimiter));

        i++;
    }
    fclose(myFile);
}

Person *createTable()
{
    Person *people = (Person *)malloc(5 * sizeof(Person));
    return people;
}

void append_person(Person *people)
{
    char tmpname[25];
    char tmpsurname[25];
    printf("Please enter your id: ");
    scanf("%d", &people[4].id);
    printf("\nPlease enter your name: ");
    scanf("%s", tmpname);
    printf("\nPlease enter your surname: ");
    scanf("%s", tmpsurname);
    strcpy(people[4].firstname, tmpname);
    strcpy(people[4].lastname, tmpsurname);
}

void delete_person(Person *people)
{
    int id;
    printf("Enter an id: \n");
    scanf("%d", &id);
    for (size_t c = id - 1; c < 4; c++)
    {
        people[c] = people[c + 1];
    }
}

int main()
{
    Person *people = NULL;
    char command;
    size_t count = 4;
    printf("Welcome to OzU Database! :)\n");
    while (TRUE)
    {
        printf("Enter a command: \n");
        scanf("%c", &command);

        if (command == 'R' || command == 'r')
        {
            if (people)
            {
                printf("Reading from CSV file..\n");
                readmy_CSV(people);
                printf("Successfully completed!\n");
            }
            else
            {
                printf("Please create the table first.\n");
            }
        }
        else if (command == 'C' || command == 'c')
        {
            people = createTable();
            printf("Table Created!\n");
        }
        else if (command == 'E' || command == 'e')
        {
            printf("Terminated successfully :)\n");
            break;
        }
        else if (command == 'A' || command == 'a')
        {
            append_person(people);
            count = count + 1;
            printf("A new person added! \n");
        }
        else if (command == 'P' || command == 'p')
        {
            printf("Printing the table..\n");
            for (int k = 0; k < count; k++)
            {
                printf("%d,%s,%s\n", people[k].id, people[k].firstname, people[k].lastname);
            }
        }
        else if (command == 'D' || command == 'd')
        {
            printf("Removing a person..\n");
            delete_person(people);
            count = count - 1;
            printf("A person has been removed! \n");
        }
    }
    return 0;
}