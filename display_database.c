#include "inverted_search.h"

//Function definition for Display database
void display_database(Wlist *head[])
{
    //print the below statements
    printf("[INDEX]   [WORD]       [FILE_COUNT]    FILE : FILE_NAME    WORD_COUNT\n");
    printf("---------------------------------------------------------------------\n");

    //for loop for printing all the lists alphabet or no. wise
    for (int i = 0; i < 27; i++)
    {
        Wlist *tempo = head[i];
        //run a while loop for raversing
        while(tempo != NULL)
        {
            //print the below statements
            printf("[%2d]      ", i);
            printf("%-15s",tempo->word);
            printf("%-15d",tempo->file_count);
            Ltable *temp1 = tempo -> Tlink;
            //while loop for traversing for subnode
            while(temp1 != NULL)
            {
                printf("FILE : %-7s  ",temp1->fname);
                printf("%-10d ",temp1->word_count);
                temp1 = temp1->table_link;
            }
            tempo = tempo ->link;
            printf("\n");
        }
    }
}
