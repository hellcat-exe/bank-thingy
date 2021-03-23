#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int pin();
int receipt();
void GCB();
int withdraw(int x);
int fastCash(int x);
int deposit(int x);
void outBal(int x);
int menu(int x);
int again(int x);

int main()
{
	int balance = rand();
	int pick;

	
	pin();
	system("cls");
	
	receipt();
	system("cls");
	
	menu(balance);
		
	return 0;
}

int pin()
{
	char input[6] = {0,0,0,0,0,0};
	
	for(int i=0;i<3;i++)
	{
		printf("enter your pin\n");
		scanf("%5s", &input);
		
		while(getchar()!='\n');
		
		//check: printf("%d\n",strlen(input));
	
		if(strlen(input)==4)
		{
			return 1;
		}
		
		printf("invalid PIN, please try again...\n");
	}
	
	printf("Sorry you can’t continue.");
	printf(" contact your bank for assistance!\n");
	
	return 0;			
}
int receipt()
{
	int n;
	
	printf("would you like a receipt? (1 for yes, 2 for no)\n");
	scanf("%d", &n);
	
	if(n==1)
	{
		return 1;
	}
	system("cls");
	return 0;
}
int fastCash(int b)
{	
	int choice;

	printf("1 --> $20,00          $40.00 <-- 2\n\n");
	printf("3 --> $80.00         $100.00 <-- 4\n\n");
	scanf("%d", &choice);
	
	system("cls");
	again(b);
	
	switch(choice)
	{
		case 1:
			if(b >= 2000)
			{
				b = b - 2000;
			}
			else
			{
				printf("insufficient funds.");
			}
			break;
		case 2:
			if(b >= 4000)
			{
				b = b - 4000;
			}
			else
			{
				printf("insufficient funds.");
			}
			break;
		case 3:
			if(b >= 8000)
			{
				b = b - 8000;
			}
			else
			{
				printf("insufficient funds.");
			}
			break;
		case 4:
			if(b >= 10000)
			{
				b = b - 10000;
			}
			else
			{
				printf("insufficient funds.");
			}
			break;	
	}
	return 0;	
}
void GCB()
{
	printf("Goodbye !");
	exit(100);
}
int withdraw(int b)
{
	int amt;
	
	printf("how much would you like to withdraw ?\n");
	scanf("%d",&amt);
	
	
	system("cls");
	
	if(b>= amt)
	{
		b = b - amt;
		again(b);
	}
	else
	{
		printf("insufficient funds.\n");
		again(b);
	}
}
int deposit(int b)
{
	int dAmt;
	
	printf("how much would you like to deposit ?\n");
	scanf("%d",&dAmt);
	
	b = b + dAmt;
	
	system("cls");
	again(b);
	return 0;
}
void outBal(int b)
{
	printf("your balance is %d\n", b);
	again(b);
}
int menu(int b)
{
	int pick;
	
	printf("1 --> Fast Cash          Deposit <-- 2\n\n");
	printf("3 --> Withdraw           Balance <-- 4\n\n");
	printf("5 --> Get Card Back\n");
	scanf("%d", &pick);
	system("cls");
	
	switch(pick)
	{
		case 1:
			fastCash(b);
			break;
		case 2:
			deposit(b);
			break;
		case 3:
			withdraw(b);
			break;
		case 4:
			outBal(b);
			break;
		case 5:
			GCB();
			break;
	}
}
int again(int b)
{
	int a;
	printf("1 --> Another transaction          Get card back <-- 2\n");
	scanf("%d", &a);
	
	system("cls");
	
	switch(a)
	{
		case 1:
			menu(b);
			break;
		case 2:
			GCB();
			break;
	}
}
