#include <stdio.h>

#include<stdlib.h>

#include<malloc.h>

#include<ctype.h>

#include<string.h>



int count=1,mks;			// c is assigned to all the question numbers and mks is the counter for marks



struct node

{

	int qno;// this is for the question number

	

	char ans;	//This is the answer which the student might input

	char rans;	//this is the correct ans as set by the teacher

	struct  node *next,*prev;

	char a[20],b[20],c[20];		// string for options

	char question_st[100];		//string for questions

};

struct node *start=NULL;



void arrange(){

	int i=1;

	struct node *ptr;

	ptr= (struct node *)malloc(sizeof(struct node));

	ptr=start;

	while(ptr->next!=start)

	{

		ptr->qno = i;

		ptr = ptr ->next;

		i++;

	}

	ptr->qno = i;

	ptr = ptr ->next;

}



struct node* create(struct node *start)

{	int x;

	struct node *new_node,*ptr,*rear;

	char A[20],B[20],C[20],e[]="exit";

	int num;

	char ques[100];

	system("cls");

	printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

	printf("\n\nenter question as 'exit' to Exit");

	printf("\nEnter Question\n");

	scanf(" %[^\n]",ques);

	x=strcmp(ques,e);

	while(x!=0){

	

	printf("\nenter option a:-\n");

	scanf(" %[^\n]",A);

	printf("\nenter option b:-\n");

	scanf(" %[^\n]",B);

	printf("\nenter option c:-\n");

	scanf(" %[^\n]",C);

	printf("\nenter the correct answer\n");

	char ans,an;

	scanf("%c",&ans);

	scanf("%c",&an);





	new_node=( struct node *)malloc(sizeof (struct node));

			new_node->qno=count;

			strcpy(new_node->question_st,ques);

			strcpy(new_node->a,A);

			strcpy(new_node->b,B);

			strcpy(new_node->c,C);

			new_node->rans=an;	

			//printf("%c",new_node->rans);

			/*printf("A-%s",new_node->a[20]);

			printf("\n %s\n", A);*/

		

		if(start==NULL)

		{

			

			start=new_node;

			start->next=start;

			//rear=new_node;

			

				

		}

		else

		{	

			ptr=start;

			while(ptr->next!=start)

			{

				ptr=ptr->next;

			}

			/*rear->next=new_node;

			new_node->prev=rear;

			rear=new_node;

				rear->next=start;

				start->prev=rear;*/

			new_node->prev=ptr;

			ptr->next=new_node;

			new_node->next=start;

			start->prev=new_node;

		



//printf("done");



		}

		printf("\n----------------------------------\n");

		printf("\n\nenter question as 'exit' to Exit");

		printf("\nEnter Question\n");

		scanf(" %[^\n]",ques);

		x=strcmp(ques,e);

		count++;



		}

	

	

	return start;

}



struct node* insert(struct node *start)

{

	struct node *ptr,*new_node;

	int qno,num;

	char ques[100],ans;

	char A[20],B[20],C[20];

	printf("\n----------------------------------\n");

	printf("\nEnter Question\n");

	scanf(" %[^\n]",ques);

	printf("\nenter option a:-\n");

	scanf(" %[^\n]",A);

	printf("\nenter option b:-\n");

	scanf(" %[^\n]",B);

	printf("\nenter option c:-\n");

	scanf(" %[^\n]",C);

	char an;

	printf("\nenter the correct ans:-\n");

	scanf("%c",&ans);

	scanf("%c",&an);

	ptr=start;

	new_node=( struct node *)malloc(sizeof (struct node));

	while(ptr->next!=start)

	{

		ptr=ptr->next;



	}

	ptr->next=new_node;

	new_node->prev=ptr;

	new_node->next=start;

	start->prev=new_node;

	strcpy(new_node->question_st,ques);

	new_node->qno=count;

	strcpy(new_node->a,A);

	strcpy(new_node->b,B);

	strcpy(new_node->c,C);

	count++;

	new_node->rans=an;	

	return start;

}



void displayprof(struct node *start)

{		arrange();

	struct node *ptr;

	ptr=start;

	system("cls");

	printf("\n-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");

	while(ptr->next!=start)

	{

		printf("%d]  %s\n\na- %s\tb- %s\tc- %s\n\n",ptr->qno,ptr->question_st,ptr->a,ptr->b,ptr->c);

		ptr=ptr->next;

	} 

	

		printf("%d]  %s\n\na- %s\tb- %s\tc- %s\n\n",ptr->qno,ptr->question_st,ptr->a,ptr->b,ptr->c);

	

}









struct node* delete(struct node *start )

{	int no;

	struct node *ptr,*temp;

	ptr=start;

	printf("enter the question number you want to delete\n");

	scanf("%d",&no);

	if(no==1)					// Delete the first question

	{

		

		while (ptr->next!=start)

		{

			ptr=ptr->next;

		}

		ptr->next=start->next;

		temp=start;

		start=start->next;

		start->prev=ptr;

		free(temp);

		

	}

	else if(count==no)			// Delete at the end

	{

		while(ptr->next!=start)

		{

			

			ptr=ptr->next;

		}

		ptr->prev->next=start;

		start->prev=ptr->prev;

		free(ptr);





	}

	else				//Any random question from 2-(n-1)

	{

		while(ptr->qno!=no)

		{

			ptr=ptr->next;



		}

		ptr->prev->next=ptr->next;

		ptr->next->prev=ptr->prev;

		free(ptr);

	}

	printf("You have successfully deleted question number : %d",no);

	count--;

	return start;



}











void Professor()

{	

	char pass[]="admin@123",scan[20];

	int opt;

	printf("Password : ");

	scanf("%s",scan);

	int s=strcmp(pass,scan);

	struct node*start1;

	if(s==0)

	{

		do{

			printf("\n----------------------------------\n");

			printf("\n 1.Create paper \n 2.Insert question \n 3.Delete question \n 4.Display \n 5.Exit\n ");

			printf("\nEnter Your Choice :: ");

			scanf("%d",&opt);

			switch(opt)

			{

				case 1:start=create(start);

						

						break;

				case 2:;

				start=insert(start);

						

						break;

				case 3:	

						start=delete(start);

						arrange();

				

						break;

				case 4:	

						displayprof(start);

						break;

				



			}

		}while(opt!=5);

		system("cls");

	}

	else

	{

		printf("wrong password");

	}





}







int checkmks()						// TO CALCULATE MARKS OF THE STUDENT ONCE EXAM IS SUBMITTED

{

	struct node *ptr;

	ptr=start;

	while(ptr->next!=start)

	{

		if(ptr->ans==ptr->rans)

		{

			mks++;

		}

		ptr=ptr->next;

	}

	if(ptr->ans==ptr->rans)

		{

			mks++;

		}



return mks;

}









void back()					// THIS IS TO REVISIT ANY QUESTION

{	int q=0;

	

	struct node *ptr;

	ptr=(struct node *)malloc(sizeof(struct node));

	ptr=start;

	printf("\n\n---------------------------------\n\n");

	printf("\n\nenter -1 to go to submit page:\n");

	printf("\nenter the question u want to revisit:-\n");

		scanf("%d",&q);

	while(q!=-1)

	{	

	

		

		while(ptr->qno!=q)

		{ptr=ptr->next;}

		printf("%d]  %s\n\na- %s\tb- %s\tc- %s\n\n",ptr->qno,ptr->question_st,ptr->a,ptr->b,ptr->c);

		printf("\nYour previous choice was :-%c\n",ptr->ans);

		printf("\nyour choice :: \n");

		scanf("%c",&(ptr->ans));

		scanf("%c",&(ptr->ans));

		printf("\n\nenter -1 to go to submit page:\n");

		printf("\nenter the question u want to revisit:-\n");
		
		scanf("%d",&q);

	}

	printf("\n\n------------------------\n\n");

	printf("Your answer was replaced\n");

	printf("\n\n------------------------\n\n");

}







int counting()

{

	struct node *ptr;

	ptr=(struct node*)malloc(sizeof(struct node));

	ptr=start;

	int x=1;

	while(ptr->next!=start)

	{

		x++;

		ptr=ptr->next;

	}

	



 return x;





}



void student()

{	int z,x,noq;

	char y,n,an,xy,o,az;

	struct node *ptr;

	ptr=start;

	system("cls");

	printf("\n\n---------------------------------\n\n");

	printf("********** ALL THE BEST *********");

	printf("\n\n---------------------------------\n\n");

	while(ptr->next!=start)

	{

		printf("%d]  %s\n\na- %s\tb- %s\tc- %s\n\n",ptr->qno,ptr->question_st,ptr->a,ptr->b,ptr->c);

		printf("Your choice:-\n");

		scanf("%c",&xy);

		scanf("%c",&az);

		ptr->ans = az;

		printf("\n\n---------------------------------\n\n");

	

//printf("%c",xy);

		ptr=ptr->next;

	}

		printf("%d]  %s\n\na- %s\tb- %s\tc- %s\n\n",ptr->qno,ptr->question_st,ptr->a,ptr->b,ptr->c);

		printf("Your choice:-");

		scanf("%c",&xy);

		scanf("%c",&az);

		ptr->ans = az;

		printf("\n\n---------------------------------\n\n");

//printf("%c",an);

	do{

		printf("\n\nDo you want to submit the test??\nEnter 1/0\n1 to submit\t\t 0 to revisit\n");

		scanf("%d",&x);

		



		if(x==1)

		{	system("cls");

			z=checkmks();

			noq = counting();

			printf("\n\n***************\n\n");

			printf("CONGRATULATIONS");

			printf("\n\n***************\n\n");

			printf("YOU SCORED ::  %d out of %d\n",z,noq);

			printf("\n\n\n\n\nTHANK YOU :)");

			exit(1);

		}

		else if(x==0)

		{

			back();

		}

		else

		{

			printf("please enter a valid choice");



		}

	}while(x!=1);

}



void main(int argc, char const *argv[])

{

	int opt;

	system("cls");

	printf("\n\n-------------WELCOME-------------\n\n");

	printf("\n\t1.Student login\n\t2.Professor login\n\t3.exit\n");

	printf("\n\nEnter Your Choice ::  ");

	scanf("%d",&opt);

	do{

	switch(opt)

		{

		 case 1: student();

			 	break;

		case 2:

				Professor();

				break;

		default:

				printf("enter a valid option");

				break;



		}

		printf("\n\n-------------WELCOME-------------\n\n");

		printf("\n\t1.Student login\n\t2.Professor login\n\t3.exit\n");

		printf("\n\nEnter Your Choice ::  ");

		scanf("%d",&opt);

	}while(opt!=3);



}

