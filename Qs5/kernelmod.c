#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/jiffies.h>
#include <linux/moduleparam.h>

int time_interval = 500;
char* name = "Anay";
module_param(name,char,);
module_param(time_interval,long,);

struct timer_list ModTimer;
static unsigned long timer_count = 0;

void TimerHandler(unsigned long data)
{
        mod_timer(&ModTimer, jiffies + msecs_to_jiffies(time_interval));
	printk(KERN_INFO "Count: %lu, Name: %s\n",++timer_count,name);
}

static int  my_init(void)
{
	printk(KERN_INFO " Module Initialised in kernel");	
	printk(KERN_INFO "Adding Timer with timeout:%lu\n",time_interval);

	setup_timer(&ModTimer,TimerHandler,0);
	add_timer(&ModTimer);
	mod_timer(&ModTimer, jiffies+msecs_to_jiffies(time_interval));

	return 0;
}


static void my_exit(void)
{
        printk("Deleting Timer\n");
	printk(KERN_INFO "Exiting Timer Module.");
}


module_init(my_init);
module_exit(my_exit);
