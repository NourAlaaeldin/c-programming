#include <stdlib.h>
#include <stdio.h>

struct _retire_info
{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double compBalance(double balance,retire_info retire)
{
  balance = balance  + balance * retire.rate_of_return/100 + retire.contribution;
  return balance;
}
void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired) //info about being retired
{
  int years =  startAge/12;
  int months = startAge%12;
  double balance = initial;
  printf("Age %3d month %2d you have $%.2lf\n",
	 years,months,balance);

  
  for(int i = 0;i <= working.months-1;i++)
    {
      months++;
      if(months%12 == 0)
	{
	  years++;
	  months = 0;
	}
      balance = compBalance(balance,working);
      printf("Age %3d month %2d you have $%.2lf\n",
	     years,months,balance);
    }
  
  for(int j = 0;j < retired.months-1;j++)
    {
      months++;
      if(months%12 == 0)
	{
	  years++;
	  months = 0;
	}
      balance = compBalance(balance,retired);
      printf("Age %3d month %2d you have $%.2lf\n",
	     years,months,balance);
    }
}
int main(void)
{
  retire_info working,retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 4.5/12;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.08333333333;
  int age = 327;
  double savings = 21345;
  retirement (age,   //in months
	      savings, //initial savings in dollars
	      working, //info about working
	      retired); //info about being retired
  return 0;
}
