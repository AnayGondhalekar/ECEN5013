#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/errno.h>
#include <linux/slab.h>

SYSCALL_DEFINE3(sortFunc ,const int __user *, src , int , len , int __user  * , dst)
{
printk("Entered System Call stringsort.\n");
int i,j;
int *buffer = NULL;
long bufflen;

if( len < 256 )
{
   printk(KERN_INFO "Invalid Buffer Size\n");
   printk("Error %d - EINVAL",EINVAL);
   return -EINVAL;
}

bufflen = (sizeof(int)*len);

buffer = (int*)kmalloc( bufflen, GFP_KERNEL);
if(!buffer)
{
   printk(KERN_INFO "Memory Allocation Failed\n");
   printk("Error %d - ENOMEM",ENOMEM);
   return -ENOMEM;
}

if (src == NULL || dst == NULL)
{
   printk(KERN_INFO "Null Pointer Error\n");
   printk("Error %d - EFAULT",EFAULT);
   return -EFAULT;
}

printk("Buffer Length is %d\n",len);
   
if(copy_from_user(buffer, src, bufflen))
{
   printk(KERN_INFO "Copy from user failed\n");
   printk("Error %d - EFAULT",EFAULT);
   return -EFAULT;
}

printk("Start of Sort");
int temp=0;

for(i=0;i<(len-1);i++)
{
	for(j=0;j<(len-i-1);j++)
	{
		if(*(buffer + j) < *(buffer + j + 1))
		{
		 temp = *(buffer + j);
		 *(buffer + j) = *(buffer + j + 1);
		 *(buffer +j +1) = temp;
		}
	}
}

printk("End of Sort");

if(copy_to_user(dst, buffer, bufflen))
{
   printk(KERN_INFO "Copy to user failed\n");
   printk("Error %d - EFAULT",EFAULT);
   return -EFAULT;
}

printk("Exited System Call stringsort.\n");

return 0;
}
