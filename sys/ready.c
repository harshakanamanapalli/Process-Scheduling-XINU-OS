/* ready.c - ready */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sched.h>

/*------------------------------------------------------------------------
 *  * ready  --  make a process eligible for CPU service
 *   *------------------------------------------------------------------------
 *    */
int ready(int pid, int resch)
{
	register struct	pentry	*pptr;

	if (isbadpid(pid))
		return(SYSERR);
	pptr = &proctab[pid];
	pptr->pstate = PRREADY;
	if(scheduler == LINUXSCHED) {
		insert(pid,rdyhead,(pptr->pprio + pptr->counter));
	} else {
		insert(pid,rdyhead,pptr->pprio);
	}
	if (resch)
		resched();
	return(OK);
}
