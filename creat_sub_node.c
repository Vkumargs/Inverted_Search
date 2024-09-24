#include "inverted_search.h"

/*Function defintion to create a sub node*/
int create_sub_node(Flist *Doc, Ltable **head)
{
    int ret;
    //create one new sub node and allocate the memory
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
    {
        return FAILURE;
    }
    //store the data inside the new node
    new->word_count = 1;
    strcpy(new->fname, Doc->file_name);
    new->table_link = NULL;

    //check if the subnode list is empty or not
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    //if the above condition fails go for else part
    else
    {
        //checking the if condition by comparing two strings
        if (strcmp(Doc->file_name, (*head)->fname) == 0)
        {
            ((*head)->word_count)++;
            return SUCCESS;
        }
        //checking if the tablelink part is null or not
        else if((*head)->table_link == NULL)
        {
            (*head) -> table_link = new;
            return FAILURE;
        }
        //declaring one new pointer and initialize
        Ltable *temp = (*head)->table_link;
        if (create_sub_node(Doc, &temp) == SUCCESS)
        {
            return SUCCESS;
        }
    }
    return FAILURE;
}