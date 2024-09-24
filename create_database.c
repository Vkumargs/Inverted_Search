#include "inverted_search.h"

// function for create database
int create_database(Flist *f_head, Wlist *head[])
{
    int ret,index;
    Flist *temp = f_head;
    //run a while loop till the condition satisfies for traverse
    while(temp)
    {
        char word[20];
        //declaring the file pointer by opening the file in read mode
        FILE *fp = fopen(temp -> file_name,"r");
        //run a while loop till the End of the file and copy the string for each turn of loop
        while(fscanf(fp, "%s",word) != EOF)
        {
            //writing some coditions to find the index value
            if(65 <= word[0] && word[0] <= 90)
            {
                index = (word[0] - 65);
            }
            else if('a' <= word[0] && word[0] <= 'z')
            {
                index = (word[0] - 'a');
            }
            else
            {
                index = 26;
            }

            //after finding the index value call a function to create main node
            if(create_main_node(temp,&head[index],word) == SUCCESS)
            {
                continue;
            }
            else
            {
                return FAILURE;
            }
        }
        // for traversing
        temp = temp -> link;
    }
    return SUCCESS;
    
}