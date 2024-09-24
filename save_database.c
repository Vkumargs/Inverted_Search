#include "inverted_search.h"

//Function defintion to save the database for backup
void save_database(Wlist *head[],char *dname)
{
    //open the file in write mode using file pointer
    FILE *file = fopen(dname,"w");
    for (int i = 0; i <= 26; i++)
    {
        Wlist *tempo = head[i];
        //run a while loop for traversing
        while(tempo != NULL)
        {
            //storint the data inside a file
            fprintf(file,"#%d;", i);
            fprintf(file,"%s;",tempo->word);
            fprintf(file,"%d;",tempo->file_count);
            Ltable *temp1 = tempo -> Tlink;
            while(temp1 != NULL)
            {
                fprintf(file,"%s;",temp1->fname);
                fprintf(file,"%d;",temp1->word_count);
                temp1 = temp1->table_link;
            }
            fprintf(file,"#\n");
            tempo = tempo ->link;
        }
    }
    printf("INFO : Save database Successfull\n");

}