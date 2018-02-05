#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define Length   	(260)
#define Stringsort      (334)
int main()
{     
    srand(time(NULL));
         
    int *srcBuffer = (int*)malloc(sizeof(int)*Length);

    printf("Randomly generated buffer is -\n");
    for(int k = 0; k < Length; k++)
    {
		srcBuffer[k] = rand()%200;
		printf("%d, ",srcBuffer[k]);
    }
    printf("\n");
//int *dstBuffer= NULL;

    int *dstBuffer = (int*)malloc(sizeof(int)*Length);

    memset(dstBuffer,0,Length);	

    
    printf("From user space to kernel space to invoke system call.\n");
    long ret = 0;
    ret = syscall(Stringsort,srcBuffer,Length,dstBuffer);
         
    if(ret == 0) 
    {
		printf("System call works correctly\n");
		printf("Sorted buffer is-\n");
		for(int i = 0; i < Length; i++)
		{
			printf("%d, ",dstBuffer[i]);
		}
		printf("\n");		
    }	
    else 
    {
         printf("System call failed Error:%ld \n",ret);
	}
	
	printf("\n");

	return (0);
}
