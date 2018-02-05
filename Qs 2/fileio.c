#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <malloc.h>
#include <sys/stat.h>

int main()
{
printf("Shoulder to Shoulder- Be Boulder\n");

//const char *file = File_Name;
FILE *fptr;
fptr = fopen("anay.txt", "w");
fputc('s',fptr);
fclose( fptr );
fptr = NULL;
//int i = chmod("anay.txt", 777);
//printf("reached");

fptr = fopen("anay.txt", "w");
fprintf(fptr, "%c",'i');

fclose( fptr );
fptr = NULL;

fptr = fopen("anay.txt", "r");

if(!fptr)
{
printf("File unable to open");
}
char *random = (char*)malloc(sizeof(char)*100);
memset(random,0,100);
printf("Enter a string.\n");
scanf("%s" , random);
fflush(fptr);
fclose(fptr); 
fptr = NULL;
//printf("reached");
memset(random,0,100);
fptr = fopen("anay.txt","r");
char val = fgetc(fptr);
fgets(random,100,fptr);
printf("The string is %s and the char value is %c. \n",random,val);
fclose(fptr);
free(random);

}




 
