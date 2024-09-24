#include "inverted_search.h"

int main(int argc, char *argv[])
{
	Flist *f_head = NULL;
	Wlist *head[27] = {NULL};
	int op, ret;
	char word[20];
	int flag1 = 0, flag2 = 0;
	if (argc <= 1)
	{
		printf("ERROR : Cla are not passed\n");
		return 0;
	}
	// checking for file validatioin
	file_validation_n_file_list(&f_head, argc, argv);

	printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save database\n6. Exit\n");
	while (1)
	{
		printf("Enter your choice : ");
		scanf("%d", &op);
		// switch case for choice making
		switch (op)
		{

			// case 1 for creating database
		case 1:
		    //check if the choice is correct or not
			if (!(flag1 || flag2))
			{
				if (create_database(f_head, head) == SUCCESS)
				{
					flag1 = 1;
					//if the above condition is satisfied then print the below statement
					printf("INFO: Create database Successfull\n");
				}
				//if the condition fails then print the else part
				else
				{
					printf("ERROR: Ceate database failed\n");
				}
			}
			//if the choice is not correct then print the else part
			else
			{
				printf("INFO : Entered WRONG choice\n");
			}
			break;

			// case 1 is for to display created database
		case 2:
			display_database(head);
			break;

			// case 3 is for updating database from a backup file
		case 3:
		    //check if the choice is correct or not
			if (!(flag2 || flag1))
			{
				if (ret = update_database(head) == SUCCESS)
				{
					flag2 = 1;
					printf("INFO : Update database is Successfull\n");
				}
				//if the file is empty then print as file empty
				else if (ret == FILE_EMPTY)
				{
					printf("INFO : File is empty\n");
				}
				//if all the above conditions fails then print the else part
				else
				{
					printf("INFO : File not found\n");
				}
			}
			//if the choice is not correct then print the else part
			else
			{
				printf("INFO : Entered WRONG choice\n");
			}
			break;

			// Case 4 is for to search for the given word
		case 4:
			printf("Enter the word : ");
			scanf("%s", word);
			if (search(head, word) == SUCCESS)
			{
				printf("INFO : Word found ---\n");
			}
			//if the condition fails then print the else part
			else
			{
				printf("ERROR: Word not found ---\n");
			}
			break;

			// case 5 is for to save database in a file for backup
		case 5:
			char dname[30];
			printf("Enter the file name : ");
			scanf("%s", dname);
			save_database(head, dname);
			break;

			// case 6 option is for exit
		case 6:
			exit(0);
			return 0;
			//if the choice if wrong then print the default statement
		default:
			printf("ERROR : Enter the correct choice !!\n");
			break;
		}
	}
}
