#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char name[50];
	int flight_num;
}pd;


void reservationA(void);
void reservationB(void);
void viewdetails(void);
void printticket(char name[],int,float);
void specificflight(int);
float charge(int);
void login();
int main()


{
	
	system("cls");
	system("COLOR 0B");
	printf("\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                    DELTA                      |\n");
	printf("\t\t|             AIRLINES MANAGEMENT SYSTEM        |\n");
	printf("\t\t|                    SYSTEM                     |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n");


	printf(" \n Press any key to continue:");
	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n\t=====================================\n");
	printf("  \t     AIRLINES MANAGEMENT SYSTEM");
	printf("\n\t=====================================");
	printf("\n\n\t1>> Reserve A Ticket To Travel In India ");
	printf("\n\t------------------------");
	printf("\n\t2>> Reserve A Ticket To Travel Through Out The World ");
	printf("\n\t------------------------");
	printf("\n\t3>> View All Available Flights");
	printf("\n\t------------------------");
	printf("\n\t4>> Exit");
	printf("\n\n\tEnter your choice from above (1-4)->>\t-->");
	scanf("%d",&menu_choice);
	
	
	switch(menu_choice)
	{
		case 1:
			
			reservationA();
			break;
			
		case 2:
			
			reservationB();
			break;

        case 3: 
        
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
			
		case 4:
			
			printf("\n\tYour Details Have Been Saved To A File(If Any)");
			return(0);
			
		default:
			
			printf("\nInvalid choice");
	}
	
	goto start;
	return(0);
	
}

void viewdetails(void)
{
	
	system("cls");
	
	
			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\nFlight.No\t Name\t\t\t\t Destinations          |\t\t\t Charges \t\t Date     \t\t Time\n");
			printf("--------------------------------------------------------------------------------------------------------------------------------------------------------");
			printf("\n1001\t\t Flight 01\t\t\t Hyderabad To Chennai  |\t\t\tRs.1500  \t\t 01 Aug 2022\t\t 10.00");
			printf("\n1002\t\t Flight 02\t\t\t Hyderabad To Goa      |\t\t\tRs.2500  \t\t 02 Aug 2022\t\t 15.00");
			printf("\n1003\t\t Flight 03\t\t\t Hyderabad To Delhi    |\t\t\tRs.7000  \t\t 03 Aug 2022\t\t 14.00");
		  	printf("\n1004\t\t Flight 04\t\t\t Hyderabad To Mumbai   |\t\t\tRs.5500	 \t\t 04 Aug 2022\t\t 19.00");
			printf("\n1005\t\t Flight 05\t\t\t Hyderabad To Kerala   |\t\t\tRs.3500	 \t\t 05 Aug 2022\t\t 11.00");
			printf("\n1006\t\t Flight 06\t\t\t Hyderabad To USA      |\t\t\tRs.90000 \t\t 06 Aug 2022\t\t 09.00");
	   		printf("\n1007\t\t Flight 07\t\t\t Hyderabad To Bangkok  |\t\t\tRs.50000 \t\t 04 Aug 2022\t\t 15.30");
	  		printf("\n1008\t\t Flight 08\t\t\t Hyderabad To Singapur |\t\t\tRs.60000 \t\t 08 Aug 2022\t\t 16.40"); 
  			printf("\n1009\t\t Flight 09\t\t\t Hyderabad To Germany  |\t\t\tRs.80000 \t\t 04 Aug 2022\t\t 19.55");
 			printf("\n1010\t\t Flight 10\t\t\t Hyderabad To SriLanka |\t\t\tRs.15000 \t\t 02 Aug 2022\t\t 15.15");


}



void reservationA(void)
{
	
	char confirm;
	int i=0;
	float charges;
	
	pd passdetails;
	FILE *fp1;
	fp1=fopen("India.txt","a");
	system("cls");
	
	printf("\nEnter Your Name :> ");
	fflush(stdin);
	gets(passdetails.name);
	
	printf("\n\n>>Press Enter To View Available flights >> ");
	getch();
	system("cls");
	viewdetails();
	
	printf("\n\nEnter flight number :> ");
	start1:
	scanf("%d",&passdetails.flight_num);
	
	if(passdetails.flight_num>=1001 && passdetails.flight_num<=1010)
	{
		charges=charge(passdetails.flight_num);
		printticket(passdetails.name,passdetails.flight_num,charges);
	}
	
	else
	{
		
		printf("\nInvalid Flight Number!");
		printf("\n Enter again --> ");
		goto start1;
		
	}

	printf("\n\nConfirm Ticket ('y' for yes/'n' for no) :>");
	start:
	scanf(" %c",&confirm);
	
	if(confirm == 'y')
	{
		fprintf(fp1,"%s\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.flight_num,charges);
		printf("\n****************************************");
		printf("\n RESERVATION DONE.......HAPPY JOURNEY :)");
		printf("\n****************************************\n");
		printf("\nPress any key to go back to Main menu");
	}
	
	else
	{
		if(confirm=='n')
		{
			printf("\nSorry to see you go :( ");
			printf("\nReservation cancelled...");
			printf("\nPress any key to go back to  Main menu!");
		}
		
		else
		{
			printf("\nInvalid choice entered! Enter again -----> ");
			goto start;
		}
		
	}
	fclose(fp1);
	getch();
	
	
}


void reservationB(void)
{
	
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp2;
	fp2=fopen("World.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\n\n>>Press Enter To View Available Flights ->> ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter flight number:> ");
	start1:
	scanf("%d",&passdetails.flight_num);
	
	if(passdetails.flight_num>=1001 && passdetails.flight_num<=1010)
	{
		charges=charge(passdetails.flight_num);
		printticket(passdetails.name,passdetails.flight_num,charges);
	}
	
	else
	{
		printf("\nInvalid Flight Number!");
		printf(" Enter again --> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	
	if(confirm == 'y')
	{
		
		fprintf(fp2,"%s\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.flight_num,charges);
		printf("\n*********************************************");
		printf("\n RESERVATION SUCCESSFUL......HAPPY JOURNEY :)");
		printf("\n*********************************************");
		printf("\n\nPress any key to go back to Main menu");
		
	}
	
	else
	{
		
		if(confirm=='n')
		{
			printf("\n\nSorry To See You Go :(");
			printf("\nReservation Not Done!");
			printf("\n\nPress any key to go back to  Main menu!");
		}
		
		else
		{
			printf("\nInvalid choice entered! \nEnter again-----> ");
			goto start;
		}
		
	}
	
	fclose(fp2);
	getch();
	
}


float charge(int flight_num)
{

	if (flight_num==1001)
	{
		return(1500);
	}
	
	if (flight_num==1002)
	{
		return(2500);
	}
	
	if (flight_num==1003)
	{
		return(7000);
	}
	
	if (flight_num==1004)
	{
		return(5500);
	}
	
	if (flight_num==1005)
	{
		return(3500);
	}
	
	if (flight_num==1006)
	{
		return(90000);
	}
	
	if (flight_num==1007)
	{
		return(50000);
	}
	
	if (flight_num==1008)
	{
		return(60000);
	}
	
	if (flight_num==1009)
	{
		return(80000);
	}
	
	if (flight_num==1010)
	{
		return(15000);
	}
	
}


void printticket(char name[],int flight_num,float charges)
{
	
	
	system("cls");
	printf("\n----------------------------------------------------------------------\n");
	printf("\t                         TICKET");
	printf("\n----------------------------------------------------------------------\n\n");
	printf("Name\t\t\t\t\t:     %s",name);
	printf("\nFlight Number\t\t\t\t:     %d",flight_num);
	specificflight(flight_num);
	printf("\nCharges\t\t\t\t\t:     %.2f",charges);
	
	
}


void specificflight(int flight_num)
{


	if (flight_num==1001)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 01 ");
		printf("\nDestination\t\t\t\t:     Hyderabad To Chennai");
		printf("\nDeparture Date and time\t\t\t:     01/08/2022-9:00am(IST) ");
		
	}
	
	if (flight_num==1002)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 02 ");
		printf("\nDestination\t\t\t\t:     Hyderabad To Goa ");
		printf("\nDeparture Date and time\t\t\t:     02/08/2022-12:00pm(IST)");
		
	}
	
	if (flight_num==1003)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 03 ");
		printf("\nDestination\t\t\t\t:     Hyderabad To Delhi");
		printf("\nDeparture Date and time\t\t\t:     03/08/2022-8:00am(IST)");
		
	}
	
	if (flight_num==1004)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 04");
		printf("\nDestination\t\t\t\t:     Hyderabad To Mumbai");
		printf("\nDeparture Date and time\t\t\t:     04/08/2022-11:00am(IST) ");
		
	}
	
	if (flight_num==1005)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 05 ");
		printf("\nDestination\t\t\t\t:     Hyderabad To Kerala");
		printf("\nDeparture Date and time\t\t\t:     05/08/2022-7:00am(IST)");
		
	}
	
	if (flight_num==1006)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 06");
		printf("\nDestination\t\t\t\t:     Hyderabad To USA");
		printf("\nDeparture Date and time\t\t\t:     06/08/2022-9:30am(IST) ");
		
	}
	
	if (flight_num==1007)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 07");
		printf("\nDestination\t\t\t\t:     Hyderabad To Bangkok");
		printf("\nDeparture Date and time\t\t\t:     04/08/2022-1:00pm(IST)");
		
	}
	
	if (flight_num==1008)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 08 ");
		printf("\n Destination\t\t\t\t:     Hyderabad To Singapur");
		printf("\nDeparture Date and time\t\t\t:     08/08/2022-4:00pm(IST)");
		
	}
	
	if (flight_num==1009)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 09");
		printf("\nDestination\t\t\t\t:     Hyderabad To Germany");
		printf("\nDeparture Date and time\t\t\t:     04/08/2022-3:35pm(IST)");
		
	}
	
	if (flight_num==1010)
	{
		
		printf("\nFlight\t\t\t\t\t:     Flight 10");
		printf("\nDestination\t\t\t\t:     Hyderabad To SriLanka");
		printf("\nDeparture Date and time\t\t\t:     02/08/2022-1:15pm(IST)");
		
	}
	
	
}


void login()
{
	
	
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
    
    
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	
	while(i<10)
	{
		
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	    
	}
	
	pword[i]='\0';
	i=0;
	
	if(strcmp(uname,"admin")==0 && strcmp(pword,"ahas")==0)
	{
		
		printf("  \n\n\n       WELCOME TO OUR  Air Lines Management System !! ");
		printf("\n\n\tYOUR LOGIN IS SUCCESSFUL :)");
		printf("\n\n\n\tPress any key to continue...");
		getch();
		break;
		
	}
	
	else
	{
		
		printf("\n\t        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		printf("\n\n\t        Enter the valid Username and Password...");
		a++;

		getch();
		system("cls");
		
	}

}


	while(a<=2);
	if (a>2)
	{
		
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
		
		
}
