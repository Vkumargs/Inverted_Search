#include "inverted_search.h"

//Fucntion to update database from backup file
int update_database(Wlist *head[])
{
    char flname[20];
    char str[100];
    printf("Enter the backupfile name: ");
    scanf("%s", flname);
    FILE *fptr;
    //check the condition by opening the file in read only mode
    if (fptr = fopen(flname, "r"))
    {
        //check if the file is empty or not
        fseek(fptr, 0, SEEK_END);
        if ((ftell(fptr)) == 0)
        {
            return FILE_EMPTY;
        }
        rewind(fptr);
        //run a while loop till the end of the file and read the string from the file
        while (fscanf(fptr, "%s", str) != EOF)
        {
            //check if the condition is satisfied or not
            if (str[0] == '#')
            {
                //if the above condition is satisfied then update the data into the list using strtok function
                char *ptr = strtok(&str[1], ";");
                //atoi function to convert character to integer
                int index = atoi(ptr);
                //creating a new main node and allocating the memory using malloc function
                Wlist *new = malloc(sizeof(Wlist));
                if(new == NULL)
                {
                    return FAILURE;
                }
                //store the data inside the new node
                strcpy(new->word, strtok(NULL, ";"));
                new->file_count = atoi(strtok(NULL, ";"));
                int flag = new->file_count;
                new->link = NULL;
                Ltable *pre = NULL;
                while (flag)
                {
                    //creating new subnode and alloacting the memory using malloc function
                    Ltable *new1 = malloc(sizeof(Ltable));
                    if (new1 == NULL)
                    {
                        return FAILURE;
                    }
                    //store the data inside the new node
                    strcpy(new1->fname, strtok(NULL, ";"));
                    new1->word_count = atoi(strtok(NULL, ";"));
                    new1->table_link = NULL;
                    if (pre != NULL)
                    {
                        pre->table_link = new1;
                    }
                    pre = new1;
                    if ((flag - (new->file_count)) == 0)
                    {
                        new->Tlink = new1;
                    }
                    flag--;
                }
                Wlist *temp = head[index];
                //check for the below conditions and ollow the satisfied condition
                if (head[index] == NULL)
                {
                    head[index] = new; 
                }
                else
                {
                    while (temp -> link)
                    {
                        temp = temp->link;
                    }
                    temp->link = new;
                }
            }
            else
            {
                return FAILURE;
            }
        }
    }
    else
    {
        return FAILURE;
    }
    return SUCCESS;
}