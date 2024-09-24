#include "inverted_search.h"

//Function defintion for searching a word
int search(Wlist *head[], char *word)
{
    int index;
    //write some conditions to find the index value
    if (65 <= word[0] && word[0] <= 90)
    {
        index = word[0] - 65;
    }
    else if (97 <= word[0] && word[0] <= 122)
    {
        index = word[0] - 97;
    }
    else
    {
        index = 26;
    }
    //check if the list is empty or not
    if(head[index] == NULL)
    {
        return FAILURE;
    }
    //call the function for searching the data
    if(search_string_data(&head[index],head[index]->Tlink,word) == SUCCESS)
    {
        //if the data is found then return success
        return SUCCESS;
    }
    else
    {
        //if the data not found then return failure
        return FAILURE;
    }
}