
#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

//defining macros
#define FAILURE   -1
#define SUCCESS    0
#define FNAME_SIZE 15
#define FNAME_SIZE_SAVE 30
#define WORD_SIZE 10
#define FILE_EMPTY -2
#define FILE_NOTAVAILABLE -3
#define REPEATATION -4

typedef char data_t;

//Structure for file list
typedef struct file_node
{
	data_t file_name[FNAME_SIZE];
	struct file_node *link;

}Flist;

//Structure for link table
typedef struct linkTable_node
{
	int word_count;
	data_t fname[FNAME_SIZE];
	struct linkTable_node *table_link;
}Ltable;

//structure to store file count and the word
typedef struct word_node
{
	int file_count;
	data_t word[WORD_SIZE];
	Ltable *Tlink;
	struct word_node *link;

}Wlist;

//Function to create list of files
int to_create_list_of_files(Flist **f_head, char *name);

//Function to create database
int create_database(Flist *f_head, Wlist *head[]);

//Function to create main node
int create_main_node(Flist *file, Wlist **head, char *word);

//Function to create sub node
int create_sub_node(Flist *file, Ltable **head);

//Function to display the database
void display_database(Wlist *head[]);

//Fucntion to search for given word
int search( Wlist *head[], char *word);

//Fucntion for searching string/word
int search_string_data(Wlist **head,Ltable *Thead,char *word);

//Function to save the database into a file for backup
void save_database(Wlist *head[],char *dname);

//Function to update the database from backup file
int update_database( Wlist *head[]);

//Function to check empty file 
int isFileEmpty(FILE *file);

//Function to check for file validation
void file_validation_n_file_list(Flist **f_head,int argc, char *argv[]);

#endif

