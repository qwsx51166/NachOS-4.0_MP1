/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"
#include "interrupt.h"
#include "synchconsole.h"

/*MP1_partI*/
void SysPrintInt(int number)
{
	kernel->interrupt->PrintInt(number);
}
/*MP1_partII*/
//int Open(char* name);
//kernel,h
int SysOpen(char *name)
{
	return kernel->interrupt->Open(name);
}

int SysWrite(char *buffer, int size, int id)
{
	return kernel->interrupt->Write(buffer, size, id);
}

int SysClose (char *name)
{
	return kernel->interrupt->Close(name);
}

void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}


int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}


#endif /* ! __USERPROG_KSYSCALL_H__ */
