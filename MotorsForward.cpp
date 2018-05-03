#include <stdio.h>
#include <time.h>
#include "E101.h"

int main(){
	init();
		
	//Motors turn on	
	set_motor(1,127); //Right Side motor, Purple and grey wires
	set_motor(2,127); //Left side motor, Orange and yellow wires
	
	//Motors stay on 1 second
	sleep1(1,0);
	
	//Motors turn off
	set_motor(2, 0);
	set_motor(1, 0);
	
	return 0;
	}
