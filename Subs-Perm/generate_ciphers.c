#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int allperms[120][5];
int ind=0;


void permute(int a[], int l, int r)  
{  
    // Base case  
    if (l == r)  
        {
            for(int i=0;i<5;i++)
             allperms[ind][i] = a[i];
             
             ++ind;
        } 
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            int temp = a[l];
            a[l]=a[i];
            a[i]=temp;
  
            // Recursion called  
            permute(a, l+1, r);  
  
            //backtrack  
            temp = a[l];
            a[l] = a[i];
            a[i] = temp;
        }  
    }  
}

int main()
{
	FILE *fptr;
	
	fptr = fopen("ciphers.txt", "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    //fprintf(fptr, "HI\n");
    char str[] = "frcspsrdynkaolyxsauttffstslslxfmknslgsecpmzlararnslaaxqvanqksktysvykcscxqcxdaxqcucymdfrcspaqnvkslszttykqabolcnfmknsswtaicdcdrnklszarnaydnskocwbscqacltuclmuanmkyedqaxnkbscvauocqxkncnutattsmnyeyneydnskocwlsanueytxbpcsmycebcvoaacqyqtslnlkcqciddcnryvyknryekvlzspcnksczlluryxaapnivivdr";
    int keylen = 5;
    int ikey[5] = { 1, 2, 3, 4, 5 };
    permute(ikey,0,4);
    
    for(int iter=0;iter<120;iter++){
    int key[5];
    for(int i=0;i<5;i++)key[i]=allperms[iter][i];
    for(int i=0;i<5;i++)fprintf(fptr, "%d",key[i]);
    fprintf(fptr, " ");
    int lenstr = strlen(str);
    char newstr[1000];
    int i,j,reqlen=0,p=0;
    for(i=0;i<lenstr;i++)
    {
        if(((int)(str[i])>=65 && (int)(str[i])<=90) || ((int)(str[i])>=97 && (int)(str[i])<=122))
        {
            reqlen++;
            newstr[p] = str[i];
            p++;
        }    
    }
    newstr[p] = '\0';
    
    int row = (reqlen+keylen-1)/keylen;
    int col = keylen;
    char grid[row][col];
    int size=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            grid[i][j] = newstr[size];
            size++;
        }
    }
    
    int x=0;
    char decipstr[reqlen];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            decipstr[x] = newstr[keylen*i + key[j] - 1];
            fprintf(fptr, "%c",decipstr[x]);
            x++;
        }
    }
    fprintf(fptr, "\n");
    }

    return 0;
}