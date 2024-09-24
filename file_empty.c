#include "inverted_search.h"

//function defintion to check if the file is empty or not
int isFileEmpty(FILE *file)
{
    //using fseek for pointing the pointer from the 0 to end
    fseek(file,0,SEEK_END);
    //check the condition using ftell for checking if the file is empty or not
    if(ftell(file))
    {
        return SUCCESS;
    }
    //if the above condition fails then return as file is empty
    else
    {
        return FILE_EMPTY;
    }
}