#include "inverted_search.h"

//Function defintion to check for the file validation
void file_validation_n_file_list(Flist **f_head, int argc, char *argv[])
{
    FILE *filename;
    int flag;
    int count = 0;

    for(int i = 1; i<argc; i++)
    {
        Flist *tempo = *f_head;

        //run a while loop for traversing
        while(tempo)
        {
            //check if condition by comparing two strings
            if(strcmp(tempo->file_name,argv[i]) == 0)
            {
                //if the condition satisfies then print the following statement
                printf("INFO : Duplicate file found, %s is already stored into the list\n",argv[i]);
                count = 1;
                break;
            }
            tempo = tempo -> link;
        }
        if(count == 1)
        {
            count = 0;
            //if the duplicate file found skip the further instructions
            continue;
        }

        //check if the file is present or not by opening the file
        if(filename = fopen(argv[i],"r"))
        {
            //check if the file empty function
            if(isFileEmpty(filename) == SUCCESS)
            {
                //if the file is not empty then call a function to create the list for files
                if(to_create_list_of_files(f_head,argv[i]) == SUCCESS)
                {
                    printf("INFO : %s is stored successfully\n",argv[i]);
                }
                else
                {
                    printf("INFO : File is not stored into the list\n");
                }
            }
            //if the file is empty then print the else part
            else
            {
                printf("ERROR: %s is empty, Hence the file is not added to the list\n",argv[i]);
            }
            continue;
        }
        //if the file not found then print the else part
        else
        {
            printf("ERROR: %s file not found\n",argv[i]);
        } 
        
    }
}