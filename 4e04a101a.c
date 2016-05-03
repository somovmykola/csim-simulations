#include "csim.h"
#include <stdio.h>

//System and simulation parameters
#define	SERVICE	10
#define TOTAL_ARRIVALS 100000
#define ARRIVAL_TIME 15
#define NUMBER_OF_FACS 1

FACILITY facs[NUMBER_OF_FACS];		
        
void customer();		
double myGen(); 

void sim()				
{
	int i=1;
	create("sim");				
	facility_set(facs, "facs", NUMBER_OF_FACS);
	//set_servicefunc(facs[0], lcfs_pr);	// This line changes the service discipline to last come first served
	//set_servicefunc(facs[0], prc_shr); This line would change the service discipline to processor sharing
	while (i<=TOTAL_ARRIVALS){
		customer();
		hold(exponential(ARRIVAL_TIME));
	    i++;
	}
	report();
}

void customer()				
{
	double r;
	create("customer");			
	use(facs[0], myGen());     
}

double myGen(){
	return exponential(SERVICE);
}