#include "inverted_search.h"

// function defintion for creating main node
int create_main_node(Flist *file, Wlist **head, char *word)
{
    int ret;
    Wlist *norm = *head;
    //check if the list is not empty
    if (norm)
    {
        //if the above condition satisfies the run a while loop for traversing
        while (norm)
        {
            //check the condition by comparing two strings
            if (strcmp(norm->word, word) == 0)
            {
                if (create_sub_node(file, &(norm->Tlink)) == SUCCESS)
                {
                    return SUCCESS;
                }
                else
                {
                    if (norm->file_count < 2)
                    {
                        norm->file_count++;
                    }
                    return SUCCESS;
                }
            }
            norm = norm->link;
        }
    }
    //create one new node by allocating some memory
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)
    {
        return FAILURE;
    }
    //store the required data inside the new node
    new->file_count = 1;
    strcpy(new->word, word);
    new->link = NULL;
    new->Tlink = NULL;

    //check if the list is empty or not
    if (*head == NULL)
    {
        *head = new;
        //after creating the main node call a function to create sub node
        if (create_sub_node(file, &((*head)->Tlink)) == SUCCESS)
        {
            return SUCCESS;
        }
    }
    //if the list is not empty then go for else part
    else
    {
        Wlist *temp = *head;
        //run a while loop for traversing
        while (temp != NULL)
        {
            if (temp->link == NULL)
            {
                temp->link = new;
                temp = temp->link;
                //after creating the main node call a function to create sub node
                if (create_sub_node(file, &(temp->Tlink)) == SUCCESS)
                {
                    return SUCCESS;
                }
                else
                    return FAILURE;
            }
            temp = temp->link;
        }
        return FAILURE;
    }
}