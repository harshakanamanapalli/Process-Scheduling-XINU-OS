#ifndef _sched_h_
#define _sched_h_

	#define DEFAULTSCHED 0
	#define EXPDISTSCHED 1
	#define LINUXSCHED 2

	void setschedclass(int _scheduler);
	int	getschedclass();
	int	get_next_process_exp(int random);
	int	linux_next_proc();
	void 	getMaxProcess(int *next, int *max);
	void 	updateGoodness();
#endif

extern int scheduler;
