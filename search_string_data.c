#include "inverted_search.h"

//Fucntion defintion for searching the string or word inside the list
int search_string_data(Wlist **head, Ltable *Thead, char *sword)
{
    Wlist *temp = *head;
    //checking if the list is empty or not
    if(temp == NULL)
    {
        return FAILURE;
    }
    else if (temp)
    {
        //run a while loop to traverse main node list
        while (temp)
        {
            //check the if condition by comparing two string
            if (strcmp(temp->word, sword) == 0)
            {
                //if the condition satisfies then print the following statements
                printf("INFO : WORD %s found in %d file/s\n",sword,(temp->file_count));
                printf("IN FILE : ");
                Ltable *hand = temp->Tlink;
                //while loop for traversing sub node list
                while(hand)
                {
                    printf("%s %d ",hand->fname,hand->word_count);
                    printf("time/s ");
                    hand = hand ->table_link;
                    if(hand != NULL)
                    {
                        printf(" , ");
                    }
                }
                printf("\n");
                return SUCCESS;
            }
            temp = temp->link;
        }
        return FAILURE;
    }
}