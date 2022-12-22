#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(void)
{
int var=1;
int* p = (int*) malloc(2);
pid_t PID = fork();
*p = 0;
if (PID >= 0)
{
if (PID == 0)
{
printf("\n\nChild Process:\n Initial Value = %d", var);
var=5;
printf("\nNew Value of var = %d", var);
printf("\nAddress of malloc in child= %p", p);
printf("\nAddress of var in child= %p\n",&var);
}
else
{
printf("\n\nParent process:\n Initial Value = %d",var);
var = 10;
printf("\nNew Value = %d", var);
printf("\nAddress of malloc in parent= %p",p);
printf("\naddress of var in child= %p\n",&var);
}
}
return 0;
}

