#include "virtualmem.h"

/*-----------the optimal page replacement function--------*/

void optimal_page_replacement(int number[1024],int k)
{
	int optimal[frame_size];
	optimal[0]=number[0];
	int x,p,q,f;
	int temp=0,flag_2=1,check=1,new=1,first=0;
	int num,num1=0,counter=0;
	for(f=1;f<frame_size;f++)
	{
		flag_2=1;
		for(x=0;x<f;x++)
		{
			if(number[x]==number[f])
			{
				flag_2=0;
				first++;
			}
		}
	}
	first=first+frame_size;
	for(f=1;f<first+1;f++)
		{
			flag_2=1;
			for(x=0;x<f;x++)
			{
				if(optimal[x]==number[f])
				{
					flag_2=0;
					break;
				}
			}
			if(flag_2==1)
			{
				optimal[new]=number[f];
				new++;
			}
		}
	for(f=first;f<k;f++)
	{
	for(x=0;x<frame_size;x++)
		{
			if(optimal[x]==number[f])
			{
				flag_2=0;
				break;
			}
			else
			{
			flag_2=1;
			}
		}
		if(flag_2==1)      /*--checking the string for future hits and positions of the pages-----*/
		{
			temp=0;
			for(p=0;p<frame_size;p++)
			{
				check=1;
				for(q=f+1;q<k;q++)
				{
					if(number[q]==optimal[p])
					{
						check=0;
						if(temp<q)
						{
							num1=p;
							temp=q;
						}
						break;
					}

				}
				if(check==1)
				{		num=p;
						break;
				}
				}
				if(check==1)
					{
						optimal[num]=number[f];
						counter=counter+1;
					}
			else
				if(check==0)
				{
				         optimal[num1]=number[f];
				         counter=counter+1;
				}
			}
	}

			for(p=0;p<frame_size;p++)
					{
						num=optimal[p];
						printf("optimal algorithm final frame is : %d\n",num);
					}
			printf("the counter for the optimal page replacement algorithm is %d \n",counter);
			printf("\n");
			printf("------------------------------------------------------------------------------------------------------------ \n ");
	optimal_count=counter;
	return;
}

void second_chance(int page_seq[1024],int k)
{
	int a[1024];
	int x,i,f1,f2=1,flag[5],f=0,temp=0,count=0,l,m=0;
	int pointer=0;
	int flag_sc=1;
	int new=1;
	int ref_bit[20];
	int lolwa =0,sc_count=-1;

		for(i=0;i<frame_size;i++)
		{
			flag[i]=temp++;
			ref_bit[i]=1;
		}
		a[0]=page_seq[0];
		for(f=1;f<frame_size+1;f++)
				{
					for(x=0;x<f;x++)
					{
						if(page_seq[f]==page_seq[x])
						{
							pointer++;
						}

					}
				}

			pointer=pointer+frame_size;
			for(f=1;f<pointer;f++)
			{
				flag_sc=1;

				for(x=0;x<f;x++)
				{

					if(page_seq[f]==page_seq[x])
					{
					flag_sc=0;
					break;
					}
				}
				if(flag_sc==1)
				{
					a[new]=page_seq[f];
					new++;
				}
			}
			lolwa=pointer;
			do
					{
					f1=0;
					f2=1;
					for(i=0;i<frame_size;i++)
					{
						if(ref_bit[i]==0)
						{
							f2=0;
						}
					}
					l=-1;
					for(i=0;i<frame_size;i++)
					{
						if(a[i]==page_seq[lolwa])
							l=i;
					}
					if(l!=-1)
					{
						if(f2==1)
						{
							count=0;
						}
						ref_bit[l]=1;
					}
					else
					{
						i=m;
						if(f2!=1)
						{
							while(ref_bit[i])
							{
								i=(i+1)%frame_size;
							}
							m=i;
							a[i]=page_seq[lolwa];
							ref_bit[i]=1;
							sc_count++;
							}
						else
						{
							sc_count++;
							a[m]=page_seq[lolwa];
							count=0;
							while(count<frame_size)
							{
								ref_bit[count]=0;
								count++;
							}
							ref_bit[m]=1;

						}

					}
	//View(page_seq);
	lolwa++;
	}while(lolwa<k);
			for(i=0;i<frame_size;i++)
			{
	printf("the value of the frame using second chance is %d \n ",a[i]);
			}
	printf("\n");
	printf("The final replacement count is : %d ",sc_count);
	printf("------------------------------------------------------------------------------------------------------------------- \n ");
	page_replacement_calculations(sc_count);
}

void View(int *a)
{
	int i;
	char c;
	for(i=0;i<frame_size;i++)
	{
		if(ref_bit[i]==1)
		c='*';
    else
		c=' ';
		printf("  %d%c  ",a[i],c);
	}
}

/*------------------------page replacement algorithm for least frequently used page ------------------------*/


void least_frequently_used(int page_sequence[1024],int k)
{
    int frame[frame_size];
    int f=0,j=0,i=0,m=0;
    int x;
    int first=0;
    int counter_lfu=0;
    int new=1;
    int age_of[1024];
    int ind=0;
    int temp=0;
    frame[0]=page_sequence[0];
    age_of[0]=1;
    int flag4=1;
    int frequency[100];
    for(m=0;m<k;m++)
        {
            frequency[m]=0;
            age_of[m]=0;
        }
    frequency[frame[0]]=1;

    for(f=1;f<frame_size;f++)
        {
            for(x=0;x<f;x++)
            {
                if(page_sequence[f]==page_sequence[x])
                {
                    first++;
               }

            }
        }


    if(first>0)
    {
        first++;
    }
    first=first+frame_size;

    for(f=1;f<first;f++)
    {
        flag4=1;

        for(x=0;x<f;x++)
        {

            if(page_sequence[f]==page_sequence[x])
            {
            flag4=0;
            frequency[page_sequence[x]]++;
            age_of[f]=page_sequence[f];
            temp++;
            break;
            }
        }
        if(flag4==1)
        {
            frame[new]=page_sequence[f];
            frequency[page_sequence[f]]++;
            age_of[f]=page_sequence[f];
            new++;
        }
    }
    age_of[0]=page_sequence[0];
    if(temp==1)
    {
        first=first-1;
    }
         for(f=first;f<k;f++)
                 {
                   flag4=1;
                    for(x=0;x<frame_size;x++)
                    {
                        if(frame[x]==page_sequence[f])
                        {
                            frequency[frame[x]]++;
                            flag4=0;
                            for(i=ind;i<f;i++)
                            {
                                if(age_of[i]==page_sequence[f])
                                {

                                    age_of[i]=0;
                                }
                             }
                            age_of[f]=page_sequence[f];
                            break;
                        }
                    }
                    if(flag4==1)
                    {
                        int min=0;
                        age_of[f]=page_sequence[f];
                        int previous_minimum=0;
                        previous_minimum=frame[0];
                        int minimum_frequency = frequency[frame[0]];
                        min=frame[0];

                     for(i=1;i<frame_size;i++)
                        {
                           if(minimum_frequency > frequency[frame[i]])
                            {

                                minimum_frequency = frequency[frame[i]];
                                min = frame[i];
                                previous_minimum=frame[i];
                             }
                        }


                        previous_minimum=frame[0];

                        for(i=1;i<frame_size;i++)
                        {
                             if(minimum_frequency==frequency[frame[i]])
                            {
                                for(j=ind;j<f;j++)
                                {
                                    if((frame[i]==age_of[j])||(previous_minimum==age_of[j]))
                                    {
                                      min=age_of[j];
                                      age_of[j]=0;
                                      if(j==ind)
                                        {
                                            ind++;
                                            if((age_of[ind]==min) || (age_of[ind]==0))
                                            {
                                                ind++;
                                            }
                                        }
                                       goto line;
                                    }
                                }
                              }
                        }
                        line:
                        counter_lfu++;
                        for(m=0;m<frame_size;m++)
                        {
                            if(frame[m]==min)
                                    {
                                        frequency[page_sequence[f]]++;
                                        frame[m]=page_sequence[f];
                                        age_of[f]=page_sequence[f];
                                    }
                        }
                    }
    }
    printf("the page replacement count for least frequently used policy is  : %d\n",counter_lfu);
    printf("------------------------------------------------------------------- \n ");
    page_replacement_calculations(counter_lfu);
}

void first_in_first_out(int page_seq[100],int k)
{

	int a[frame_size];
	int f=0;

	int x;
	int first=0,count=0,new=1;
	a[0]=page_seq[0];
	int flag_1=1,index=-1;

	for(f=1;f<frame_size;f++)
	{
		for(x=0;x<f;x++)
		{
			if(page_seq[f]==page_seq[x])
			{
			flag_1=0;
			first++;
			}
		}
	}
	first=first+frame_size;
	for(f=1;f<first+1;f++)
	{
		flag_1=1;
		for(x=0;x<f;x++)
		{

			if(page_seq[f]==page_seq[x])
			{
			flag_1=0;
			break;
			}
		}
		if(flag_1==1)
		{
			a[new]=page_seq[f];
			new++;
		}
	}
	for(f=first;f<k;f++)
		 	{
				flag_1=1;
				for(x=0;x<frame_size;x++)
				{
					if(a[x]==page_seq[f])
					{
						flag_1=0;
						break;
					}
				}
				if(flag_1==1)
				{
					index++;
					if(index==frame_size)
					{
						index=0;
					}
					count++;

					a[index]=page_seq[f];
					}
	}

				for(f=0;f<frame_size;f++)
					{
					printf("value of frame using FIFO is : %d\n",a[f]);
					}
	printf("the page replacement count is : %d\n",count);
	page_replacement_calculations(count);
}

/*-----------function to calculate all the page replacements of different page replacement algorithms--------*/
void page_replacement_calculations(int type)
{
	int difference;
	int total;
	total=optimal_count;
	float final;
	printf("page replacement algorithm gives %d and optimal gives %d \n",type,total);
	difference=type-total;
	final=(float)difference/total;
	final=final*100;
	printf("-----------------------------------------------------");
	printf("\n penalty is %f\n",final);
}



/*---------------------main function-------------------*/


int main(int argc,char* argv[])
{
	  char* option;
	  char option_to_exit[10];
	  int i=0;
	  i_flag=0;

	  for(i=0;i<argc;i++)
	  {
		  option=strdup(argv[i]);
		    	switch(option[1])
		    	{
		    	case 'h':
		    		printf("\n−h : Print a usage summary with all options and exit.\n");
		    		printf("\n−f available-frames : Set the number of available frames. By default it should be 5.\n");
		    		printf("\n−r replacement-policy : Set the page replacement policy. It can be either FIFO (First-in-first-out), SC (second chance/clock), or LFU (Least-frequently-used). The default will be FIFO.\n");
		    		printf("\n−i input file\n");
		    		  printf("\n do you want to exit (yes/no)");
		    		  scanf("%s",option_to_exit);

		    		  if((strcmp(option_to_exit,"yes"))==0)
		    		  {
		    		  exit(0);
		    		  }
		    		  break;

		    	case 'f':
		    		frame_size=atoi(argv[i+1]);
		    		printf("no of frames %d\n",frame_size);
		    		break;

		    	case 'r':
		    		page_replacement_algo=strdup(argv[i+1]);
		    		if(strcmp(page_replacement_algo,"FIFO")==0)
		    				    		{
		    				    			flag=0;
		    				    		}
		    		else if(strcmp(page_replacement_algo,"SC")==0)
		    		{
		    			flag=2;
		    		}
		    		else if(strcmp(page_replacement_algo,"LFU")==0)
		    		{
		    			flag =1;
		    		}
		    		break;

		    	case 'i':
		    		i_flag=1;
		    		file_name = strdup(argv[i+1]);
		    		file_input();
		    		break;
		    	}
	  }
	  if(i_flag==0)
	  {
		  console_input();
	  }

return 0;
}
