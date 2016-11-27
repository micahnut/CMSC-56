#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000


	int isNum(char []);
	int length(char[]);
	int isAlpha(char []);
	int anagram(char[], char[]);

int main(){
     char string[50],num[50];
     int spcnt[50],i,j,c;
     int k;
     int choice1;
     char first[SIZE],second[SIZE];
    int flag, flag2=0;
    int userpin, pin, choice, accnum, checkingbal, bal, trans, transamt, savingsbal, useracc, depsav, depcheck, acctype, withdrawsav, again=1, withdrawcheck;
    
     
     do{
		printf("\t\t\tMENU\n\t1. Anagram \n\t2. Encyption \n\t3. Decyption \n\t4. Teller Machine \n\t5. Exit\n");
		scanf("%i",&choice1);
		
		if(choice1==1){
			if(flag2 == 0) {
				printf("\nANAGRAM CHECKER\n\nWhat is an Anagram?\n -An anagram is a a word, phrase, or name formed by rearranging the letters of another, such as cinema, formed from iceman.\n\nInstruction:\n This program is called an Anagram Checker. A User must enter two(2) words, a first word and a second word.\n The program checks if the second word is ananagram of the first word\n");
    			flag2 = 1;
    		}
			printf("\nUser, please, enter the first word:\t");
    		fflush(stdin);
			scanf(" %[^\n]s", first);
    		printf("\nUser, please, enter the second word:\t");
    		fflush(stdin);
			scanf(" %[^\n]s", second);
    
    		flag = anagram(first, second);
    
  		  if(flag == 1)
        		printf("\nTHE WORD '%s' IS AN ANAGRAM OF '%s'.\n\n", first, second);
    	else 
    	if(flag == 0)
    		    printf("\nTHE WORD '%s' IS *NOT AN ANAGRAM OF '%s'.\n\n", first, second);
			
		}
		
	else if(choice1 == 2){
	
     
	  printf("This Program will encrypt according to your needs\n");
	 
	 do{
     	printf("Enter a string : ");
     	fflush(stdin);
    	scanf(" %[^\n]s", &string);
	 }while(!(isAlpha(string)));
	
	
	printf("De-Encoded string is as follow : %s \n",string);
	
	do{
		printf("Enter the cipher key:\n");
		 fflush(stdin);
		scanf("%s",&num);
	}while(!(isNum(num)));
	
	k=atoi(num);
	
	if(k>=26)
		k=k%26;
		
	else if(k>=0)
	 k=k;
	 
	else 
	 return 0;
	  			
	
	for (j = 0; string[j] != '\0'; j++)  {
        if (string[j] >= 'A' && string[j] <= 'Z') {
            if (string[j] + k <= 'Z')
                string[j] = string[j] + k;
            
            else if ((string[j] + k) > 'Z')
                string[j] = (string[j] + k) - 26;
        }
         else if (string[j] >= 'a' && string[j] <= 'z') {
            if (string[j] + k <= 'z')
                string[j] = string[j] + k;
             
            else if ((string[j] + k) > 'z')
                string[j] = (string[j] + k) - 26;
        }
         else {
            string[j] = string[j];
          }
     }  
     
     printf("Encoded string is as follow : %s \n\n",string);
     
}
	else if(choice1 == 3){
		  printf("This Program will decrypt according to your needs\n");
	 
	 do{
     	printf("Enter a string : ");
     	fflush(stdin);
    	scanf(" %[^\n]s", &string);
	 }while(!(isAlpha(string)));
	
	
	printf("De-Encoded string is as follow : %s \n",string);
	
	do{
		printf("Enter the cipher key:\n");
		 fflush(stdin);
		scanf("%s",&num);
	}while(!(isNum(num)));
	
	k=atoi(num);
	
	if(k>=26)
		k=k%26;
		
	else if(k>=0)
	 k=k;
	 
	else 
	 return 0;
	  			
	int temp;
	
	for (j = 0; string[j] != '\0'; j++)  {
        if (string[j] >= 'A' && string[j] <= 'Z') {
          
		    if (string[j] - k >= 'A')
                string[j] = string[j] - k;
            
            else if ((string[j] - k) < 'A')
                string[j] = (string[j] - k) + 26;
                
    		
        }
         else if (string[j] >= 'a' && string[j] <= 'z') {
            if (string[j] - k >= 'a')
                string[j] = string[j] - k;
             
            else if ((string[j] - k) < 'z')
                string[j] = (string[j] - k) + 26;
                
        }
         else {
            string[j] = string[j];
          }
     }  
     
     printf("Encoded string is as follow : %s \n\n",string);
     
	}
	
	else if(choice1 == 4){
		srand(time(NULL));
	
	accnum = rand()%99999;
	pin = rand()%999;

	checkingbal = rand()%99999;
	savingsbal = rand()%99999;

//	system("cls");

	printf ("savings bal: %d\n\n", savingsbal);	
	printf ("Please take note of the following numbers\n\n\tACCOUNT NUMBER:\t%d\n\tPIN:\t%d\n\nPress enter to continue...\n", accnum, pin);
	
	getchar();
	system("cls");

	
	while (useracc!=accnum){
		printf ("\nENTER ACCOUNT NUMBER:\t");
		fflush(stdin);
		scanf("%d", &useracc);
	}

	while (userpin!=pin){
		printf ("\nENTER PIN:\t");
		scanf("%d", &userpin);
	}
	
while(again == 1)
	{
	
	if(userpin==pin){
		printf ("\n\n   WELCOME TO CMSC56's ATM\n\n");
		printf ("\t (1) Withdraw\n\t (2) Deposit\n\t (3) Transfer\n\t (4) Balance Inquiry\n\n");
		printf ("Enter the number of choice:\t");
		scanf ("%d", &choice);
	}

	switch (choice){
		case 1://WITHDRAW
			{
				printf ("\nWhich account would you like to access?\n");
				printf ("\n(1) Savings\n(2) Checking\n");
				scanf ("%d", &acctype);
				
				//SAVINGS WITHDRAW
				if (acctype==1){
						printf ("How much would you like to withdraw from your savings account?: \n");
						scanf ("%d", &withdrawsav);
						
						savingsbal =  savingsbal - withdrawsav;
						
						printf ("\nSuccess.\n");
						printf ("\nYour new savings account balance is %d Php\n", savingsbal);
						printf ("\nWould you like to make another transaction?\n");
						printf ("(1) Yes / (2) No \n");
						scanf ("%d", &again);
				}
				//CHECKING WITHDRAW
				else if (acctype==2){
						printf ("How much would you like to withdraw from your checking account?: \n");
						scanf ("%d", &withdrawcheck);
						
						checkingbal =  checkingbal - withdrawcheck;
						
						printf ("\nSuccess.\n");
						printf ("\nYour new savings account balance is %dPhp\n", checkingbal);
						printf ("\nWould you like to make another transaction?\n");
						printf ("(1) Yes / (2) No \n");
						scanf ("%d", &again);
				}
			
			}
		break;
		
		case 2://DEPOSIT
			{
				printf ("\nWhich account would you like to access?\n");
				printf ("\n(1) Savings\n(2) Checking\n");
				scanf ("%d", &acctype);
				
				//SAVINGS DEPOSIT
				if (acctype==1){
						printf ("How much would you like to deposit from your savings account?: \n");
						scanf ("%d", &depsav);
						
						savingsbal =  savingsbal + depsav;
						
						printf ("\nSuccess.\n");
						printf ("\nYour new savings account balance is %d Php\n", savingsbal);
						printf ("\nWould you like to make another transaction?\n");
						printf ("(1) Yes / (2) No \n");
						scanf ("%d", &again);
				}
				//CHECKING DEPOSIT
				if (acctype==2){
						printf ("How much would you like to deposit from your checking account?: \n");
						scanf ("%d", &depcheck);
						
						checkingbal =  checkingbal + depcheck;
						
						printf ("\nSuccess.\n");
						printf ("\nYour new savings account balance is %d Php\n", checkingbal);
						printf ("\nWould you like to make another transaction?\n");
						printf ("(1) Yes / (2) No \n");
						scanf ("%d", &again);
				}
			}
			
			break;
			
		case 3: //TRANSFER
		{
			printf ("Which account would you like to transfer from?\n\n\t(1) Checking\n\t(2) Savings\n");
			scanf ("%d", &trans);
			
			if (trans==1){
				printf ("\nHow much would you like to transfer from your checking account?: \n");
				scanf ("%d", &transamt);
				
				checkingbal -= transamt;
				savingsbal += transamt;
				
				printf ("\nSuccessfully transfered %d from your checking to your savings account.\n", transamt);
				printf ("\nYour current savings balance: %d\t\nYour current checking balance: %d\t\n", savingsbal, checkingbal);
				printf ("Would you like to make another transaction?\n");
				printf ("(1) Yes / (2) No \n");
				scanf ("%d", &again);
			}
			if (trans==2){
				printf ("\nHow much would you like to transfer from your savings account?: \n");
				scanf ("%d", &transamt);
				
				savingsbal -= transamt;
				checkingbal += transamt;
				
				printf ("\nSuccessfully transfered %d from your checking to your savings account.\n", transamt);
				printf ("\nYour current savings balance: %d\t\nYour current checking balance: %d\t\n", savingsbal, checkingbal);
				printf ("Would you like to make another transaction?\n");
				printf ("(1) Yes / (2) No \n");
				scanf ("%d", &again);
			}
			else{
				printf ("\nSomething isn't right. Try again later.\n");
			}
		}
		
		break;
		
		case 4: //BALANCE INQUIRY
		{
			printf ("Which account would you like to access?\n\t(1) Checking\n\t(2) Savings");
			scanf ("%d", &bal);
				
			if (bal==1){
				printf ("Your account balance for your Checking account is %d.\n", checkingbal);
				printf ("Would you like to make another transaction?\n");
				printf ("(1) Yes / (2) No \n");
				scanf ("%d", &again);
			}
			if (bal==2){
				printf ("Your account balance for your Savings account is %d.\n", savingsbal);
				printf ("Would you like to make another transaction?\n");
				printf ("(1) Yes / (2) No \n");
				scanf ("%d", &again);
			}
	
		}
				
		break;
	}
	
}

	}
	
	else if (choice1 == 5 ){
		printf("Exit\n");
		break;	
	}
	
	else
		printf("Not one of the choices!\n");
	
	}while(choice1!=5);
	
	getch();
	return 0;
}

  int length(char st[]){
	int i=0;
	for(;st[i]!='\0';i++);
	return i;		
	}
	
	int isAlpha(char st[]){
		int i=0, flag = 1, len;
		len = length(st);
		for(;i<len;i++){
		if(!((st[i]>='a' && st[i]<='z')|| (st[i]>='A' && st[i]<='Z')|| (st[i]==' ') || (st[i]=='.'))){
			flag=0;
			break;
		}
		}
		return flag;
	}
	
	int isNum(char st[]){
		int i=0,flag=1,len;
		len = length(st);
		for(;i<len;i++){
		if(!(st[i]>='0' && st[i]<='9')){
			flag=0;
			break;
 	 	}
      }
		return flag;
	}		    
    
    int anagram(char first[], char second[]){
    
    char a[SIZE], b[SIZE];
    int i, j;
    
    strcpy(a, first);
    strcpy(b, second);
    
    for(i=0; a[i] != '\0'; i++){
        for(j=0; b[j] != '\0'; j++){
        	if(a[i] == ' '){
        		a[i] = '0';
			}
			if(b[j] == ' '){
        		b[j] = '0';
			}
            if(a[i] == b[j]){
                a[i] = '0';
                b[j] = '0';
                break;
            }
        }
    }
   
    for(i=0; a[i] != '\0'; i++){
        if(a[i] != '0')
            return 0;
    }
    for(j=0; b[j] != '\0'; j++){
        if(b[j] != '0')
            return 0;
    }
    
    return 1;
}
