# Project advancement
## Beginning
The project was started with creating a README.md and documentaion folder

The environment required a bit of extra setup this time. an older version of gcc was required to get the source to compile and qemu installation was required to emulate the code. I went with gcc-9, which worked.

After getting the source and doing the intitial compile and emulation, the running of the stock project was confirmed and the building of a custom system call can begin.

## Buliding
The system call is ment to return the ammount of times the read system call has been made since boot. Thus the first step is to add the counter to sysproc.s to be initialised. after this the system call sys_read needs to be edited to increment the counter on use.

After this work on the system call to read the counter can begin. in syscall.h a new call SYS_getreadcount is added, and in syscall.c the new system call is added to extern declarations and the syscalls array. Then the systemcall itself can be made by adding it to sysproc.d.

Lastly the systemcall is opened to user space by adding it to usys.S and in user.h

### debuging

During building a quite obvious oversight can be spotted. sysproc.c cant access the readcount as it is not glogal. This could be fixed by removing static from the variable declaration, however this doesn't feel right. A better way to fix this is to move the system call for getting the read count, to sysfile.c

## Testing
To test te functionality, a simple uses level program is written and added to the makefile for user programs. This simple readcounttest reads the variable value, uses the read function, reads the value again and prints both. With this the functionaliy can be ensured.
