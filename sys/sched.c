/* sched.c - get_next_process_exp, reallocate, linux_next_proc */

#include <kernel.h>
#include <q.h>
#include <proc.h>
#include <sched.h>

int get_next_process_exp(int random)
{
	int proc, prev_proc;

	for(proc = q[rdytail].qprev, prev_proc = proc; (random < q[proc].qkey) && (proc < NPROC); proc = q[proc].qprev){
		if(q[proc].qkey != q[prev_proc].qkey){
			prev_proc = proc;
		}
	}

	if(proc >= NPROC)
		return EMPTY;
	else
		return prev_proc;
}

void getMaxProcess(int *next, int *max){
	*next = 0;
	*max = 0;
	
	int iter = q[rdytail].qprev;
	while(iter != rdyhead){
		if(proctab[iter].goodness > *max){
			*next = iter;
			*max = proctab[iter].goodness;
		}
		iter = q[iter].qprev;
	}
}

void updateGoodness(){
	int temp_process_id;
	struct pentry *temp_process;

	if(NPROC > 0){
		do{
			temp_process = &proctab[temp_process_id];
			if(temp_process->pstate != PRFREE){
				temp_process->counter = temp_process->pprio + (temp_process->counter)/2;
				temp_process->goodness = temp_process->pprio + temp_process->counter;
			}
			temp_process_id++;
		}while(temp_process_id < NPROC);
	}
}
