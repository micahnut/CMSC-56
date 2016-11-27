#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * CMSC 56 Machine Problem 1
 */

//Arbitrary, just to set the size of the buffer (see below).
#define BUFSIZE 1000

int checkIfBin(char[]);
char *BitOper(char[], char[], char[]);


int main(int argc, char *argv[])
{

    
    FILE *ifp, *ofp;
    ifp = fopen("mp1-small.in", "r"); // read mode
    ofp = fopen("small.out", "w"); // write mode

    char buff[BUFSIZE];
    char bit1[BUFSIZE];
    char bit2[BUFSIZE];
    char oper[BUFSIZE];

    if( ifp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    if(ofp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(buff, BUFSIZE-1, ifp) != NULL)
    {
        sscanf(buff, "%s %s %s", bit1, bit2, oper); //Stores the information from buff into separate strings.
        if(strcmp(oper, "OR") != 0 && strcmp(oper, "AND") != 0 && strcmp(oper, "XOR") != 0) 
        {
            strcpy(buff, "ERR\n");

        }
        else if((checkIfBin(bit1) ==  0) || (checkIfBin(bit2) == 0))
        {
            strcpy(buff, "ERR\n");
        }
        else
        {
            strcpy(buff, BitOper(bit1, bit2, oper));
        }
        fprintf(ofp, "%s", buff);
    }

    fclose(ifp);
    fclose(ofp);
    return 0;
}

int checkIfBin(char BinValue[])
{
    int i;
    for (i = 0; BinValue[i] != '\0'; i++)
    {
        if (BinValue[i] != '0' && BinValue[i] != '1')
            return 0;
    }

    return 1;
}


char *BitOper(char bit1[], char bit2[], char oper[])
{
    char *bitresult, *bit1rev, *bit2rev;
    int i, nsmall, nbig, n1, n2, bit;

    n1 = strlen(bit1); 
    bit1rev = malloc((sizeof(char) * n1) + 1);
    bit1rev= strrev(bit1);
	
    n2 = strlen(bit2);
    bit2rev = malloc((sizeof(char) * n2) + 1);
    bit2rev= strrev(bit2);
   	
    if(n1>n2)
    	nbig=n1;
	else
		nbig=n2;		
	
	if(n1<n2)
		nsmall=n1;
	else
		nsmall=n2;	
	

    bitresult = malloc((sizeof(char) * nbig) + 2);
    for (i = 0; i < nbig; i++)
    {
        if(i < nsmall)
        {
            bit = ((int)bit1rev[i] - 48) + ((int)bit2rev[i] - 48);
            if(strcmp(oper, "AND") == 0)
            {
                if(bit == 2)
                    bitresult[nbig - (i+1)] = '1';
                else
                    bitresult[nbig - (i+1)] = '0';
            }

            else if(strcmp(oper, "OR") == 0)
            {
                if(bit == 0)
                    bitresult[nbig - (i+1)] = '0';
                else
                    bitresult[nbig - (i+1)] = '1';
            }

            else
            {
                if(bit == 1)
                    bitresult[nbig - (i+1)] = '1';
                else
                    bitresult[nbig - (i+1)] = '0';
            }
        }

        else
        {
        	if(n1>n2)
        		bit= (int)bit1rev[i]-48;
        	else
        		bit= (int)bit2rev[i]-48;
        		
            bitresult[nbig - (i+1)] = (char)(bit + 48);
        }
    }
    bitresult[nbig] = '\n';
    bitresult[nbig + 1] = '\0';

    return bitresult;
}
