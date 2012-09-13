/*
 * virtualmem.h
 *
 *  Created on: Nov 21, 2011
 *      Author: mustafa
 */
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<signal.h>
#include<math.h>

int ref_bit[20];
int frame_size=5;
char *page_replacement_algo;
int flag,i_flag;
int name[10];
char *file_name;
int optimal_count;

void optimal_page_replacement(int number[500],int k);
void first_in_first_out(int number[100],int k);
void least_frequently_used(int number[1024],int k);
void second_chance(int number[1024],int k);
void page_replacement_calculations(int type);
void console_input();
void View(int *a);

void file_input()
{
	FILE *fp;
	int number,k=0;
	int page_sequence[1024];
	fp=fopen(file_name,"r");
	while(fscanf(fp,"%d",&number) != EOF)
	{
	  page_sequence[k]=number;
	  k++;
	}
	printf("reading input sequence from the file");
	optimal_page_replacement(page_sequence,k); //optimal function is called even if it is not specified for


/*------------calling of particular functions if the particular flag is raised------------*/
	if(flag==0)
	{
		first_in_first_out(page_sequence,k);
	}
	else if(flag==1)
	{
		least_frequently_used(page_sequence,k);
	}
	else if(flag==2)
	{
		second_chance(page_sequence,k);
	}
}


void console_input()
{

	    int sum = 0;
		char line[1024];
	    char *buffer;
	    int length;
		int buffer_length=10;
		int number[10];
		int error_number;
		line[0] = '\0';
	    buffer = fgets(line, sizeof(line), stdin);
	    length = strlen(buffer);
	    buffer[length] = 0;
	    length = length/2;
	    length += 1;
	    buffer_length = length;
	    int index =0;
	    char *ptr=buffer;

	  while (1)
	       {

	         char *last;
	         int next;

	         while(isspace(*ptr)) ptr++;
	         if (*ptr== 0)
	         break;
	         error_number = 0;
	         next = strtol (ptr, &last, 0);
	         if (error_number)
	         printf (" buffer Overflow\n");
	         else
	           sum += next;
	         ptr = last;

	         number[index]=next;
	         index++;
	       }

	  optimal_page_replacement(number,index);

	       	 if(flag==0)
	       	{
	       		first_in_first_out(number,index);
	       	}
	       	else if(flag==1)
	       	{
	       		least_frequently_used(number,index);
	       	}
	       	else if(flag==2)
	       	{
	       		second_chance(number,index);
	       	}


  }
