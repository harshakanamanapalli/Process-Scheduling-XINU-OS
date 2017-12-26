#include <kernel.h>
#include <math.h>
#include <sched.h>

void setschedclass(int _scheduler){
	scheduler = _scheduler;
}

int getschedclass(){
	return scheduler;
}
