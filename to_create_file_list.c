#include "inverted_search.h"

//Function to create list to store the file names
int to_create_list_of_files(Flist **f_head, char *name)
{
    //creating one new node and allocate the memory
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
    {
        return FAILURE;
    }
    //store the data inside the new node
    strcpy(new->file_name, name);
    new->link = NULL;

    //check if the list is empty or not
    if(*f_head == NULL)
    {
        (*f_head) = new;
        return SUCCESS;
    }
    //if the list is not empty then do the else part
    else
    {
        Flist *temp = *f_head;
        //while loop for traversing
        while(temp)
        {
            if(temp -> link == NULL)
            {
                temp -> link = new;
                return SUCCESS;
            }
            temp = temp -> link;
        }
        return SUCCESS;
    }

}