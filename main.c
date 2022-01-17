#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cricketer
{
  char name[20];
  char type[15];
  char country[20];
  float average_score;
  int wickets,age ,runs, odi, t;
};

void avgscr_sort(struct cricketer p[], int n)
{
  struct cricketer p1;
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      if(p[i].average_score < p[j].average_score)
      {
        p1 = p[i];
        p[i] = p[j];
        p[j] = p1;
      }
    }
  }
  printf("\nThe SORTED Details of players are : \n");
      printf("\nName\t\tCountry\t\tAge\t\tType\t\tAvgScore \tWickets \tRuns\t\tODI matches\t\tT20 matches\n");
      for(int i=0; i<n; i++)
      {
        printf("%s \t\t%s\t\t%d\t\t%s\t\t%.2f\t\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].name, p[i].country, p[i].age, p[i].type, p[i].average_score, p[i].wickets, p[i].runs, p[i].odi, p[i].t);
      }
      printf("\n");

}

int main(void) 
{
  struct cricketer p[100];
  int i,n,max1,max2,index,index2,bat_c,bowl_c,all_c,bat,bowl,all,wk;
  char nm[20], c_bat[20], c_bowl[20], c_all[20], c[20];
  printf("\t\t\t\t\tCricket Players Display Board");
  printf("\nEnter number of players : \n");
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    printf("\nEnter Data of player %d Below⬇️", i+1);
    printf("\nName : ");
    scanf("%s", p[i].name);
    printf("Country :  ");
    scanf("%s", p[i].country);
    printf("Age :  ");
    scanf("%d", &p[i].age);
    printf("Type :  ");
    scanf("%s", p[i].type);
    printf("average Score : ");
    scanf("%f", &p[i].average_score);
    printf("Wickets Taken : ");
    scanf("%d", &p[i].wickets);
    printf("Runs Scored : ");
    scanf("%d", &p[i].runs);
    printf("no. of ODIs played : ");
    scanf("%d", &p[i].odi);
    printf("no. of T20s played : ");
    scanf("%d", &p[i].t);
    printf("\n");
  } 

  int choice,num;
  
  while(1)
  {
    printf("\n1.Sort players .\n2.Search for a particular player .\n3.Display players .\n4.Type of player.\n5. Batsman of a country.\n 6.Bowlers of a country.\n7.Highest wickets.\n8.Players of a country.\n9.Exit.\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1 : avgscr_sort(p, n);
      break;

      case 2 : 
      printf("\nEnter name of the player:\n");
      scanf("%s", nm);
      for(i=0;i<n;i++)
      {
        if(strcmp(nm,p[i].name)==0)
       {
        printf("name: %s\ntype: %s\naverage: %.2f\nwickets: %d\nruns: %d\n", p[i].name,p[i].type,p[i].average_score,p[i].wickets,p[i].runs);
       }
      }
      break;

      case 3 :
      printf("\nThe Details of players are : \n");
      printf("\nName\t\tType\t\tAvgScore \tWickets \tRuns\n");
      for(int i=0; i<n; i++)
      {
        printf("%s \t\t%s\t\t%.2f\t\t\t%d\t\t%d\n", p[i].name, p[i].type, p[i].average_score, p[i].wickets, p[i].runs);
      }
      printf("\n");
      break;

      case 4 :
      bat=0;
      bowl=0;
      all=0;
      wk=0;
      for(i=0;i<n;i++)
      {
        if(strcmp("Batsman",p[i].type)==0)
        {
          bat++;
        }
        else if(strcmp("Bowler",p[i].type)==0)
        {
          bowl++;
        }
        else if(strcmp("AllRounder",p[i].type)==0)
        {
          all++;
        }
        else if(strcmp("WicketKeeper",p[i].type)==0)
        {
          wk++;
        }
      }
      printf("Number of batsman: %d\nNumber of Bowlers: %d\nNumber of all rounders: %d\nNumber of wicket keepers: %d\n",bat,bowl,all,wk);
      break;

      case 5 :
      bat_c=0;
      printf("Enter name of a country:\n");
      scanf("%s", c_bat);
      for(i=0;i<n;i++)
      {
        if(strcmp(c_bat,p[i].country)==0)
        {
          if(strcmp("Batsman",p[i].type)==0)
          bat_c++;
        }
      }
      printf("%s has %d batsmen.\n", c_bat, bat_c);
      break;

      case 6 : 
      bowl_c=0;
      printf("Enter name of a country:\n");
      scanf("%s", c_bowl);
      for(i=0;i<n;i++)
      {
        if(strcmp(c_bowl,p[i].country)==0)
        {
          if(strcmp("Bowler",p[i].type)==0)
          {
            bowl_c++; 
          }
          
        }
      }
      printf("%s has %d bowlers.\n", c_bowl, bowl_c);
      break;
      
      
      case 7 :
      max2=0, index2=0;
      for(i=0;i<n;i++)
      {
        if(strcmp("Bowler",p[i].type)==0)
        {
          if(p[i].wickets>max2)
          {
            max1=p[i].wickets;
            index2=i;
          }
        }
      }
      printf("Highest wickets taken: %d by %s\n", p[index2].wickets, p[index2].name);
      break;

      case 8 :
      printf("Enter name of a country:\n");
      scanf("%s", c);
      for(i=0;i<n;i++)
      {
        if(strcmp(c,p[i].country)==0)
        {
          printf("Name: %s\nAge: %d\nType: %s\nRuns: %d\nWickets: %d\nODIs played: %d\nT20s played: %d\nAverage: %.2f\n",p[i].name,p[i].age,p[i].type,p[i].runs,p[i].wickets,p[i].odi,p[i].t,p[i].average_score);
        }
      }
      break;

      case 9 :
      printf("You have opted to exit the program. Have a great day ahead!!\n");
      return 0; 

      default : 
      printf("\nEnter a valid choice !!...\n");
      break;
    }
  }
  
  
  return 0;
}