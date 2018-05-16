#include <stdio.h>
#include <time.h>
#include "E101.h"

int distance = 50; //Distance from wall

double distance_measure(double distance, int adc_reading_front, int adc_reading_right){
	if(adc_reading_front > distance && adc_reading_right > distance){
			turn_left(int norm_speed, slow_speed, int off_speed)
	}
	if(adc_reading_front < distance && adc_reading_right > distance){
			straight(int norm_speed, int off_speed)
	}
	if(adc_reading_front > distance && adc_reading_right < distance){
			turn_right(int norm_speed, slow_speed, int off_speed)
	}
	if(adc_reading_front < distance && adc_reading_right < distance){
			turn_right(int norm_speed, slow_speed, int off_speed)
	}
}
	
int slow_speed = 30; //Slow speed can be left or right
int norm_speed = 40;
int off_speed = 0; //Normal speed of wheels

void turn_left(int norm_speed, int slow_speed, int off_speed){
	set_motor(2, slow_speed); //Left wheel
	set_motor(1, norm_speed); //Right wheel
	sleep1(0, 500);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
	}

void turn_right(int norm_speed, int slow_speed, int off_speed){
	set_motor(2, norm_speed); //Left wheel
	set_motor(1, slow_speed); //Right wheel
	sleep1(0, 500);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
	}
	
void straight(int norm_speed, int off_speed){
	set_motor(2, norm_speed); //Left wheel
	set_motor(1, norm_speed); //Right wheel
	sleep1(0, 500);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
	}
	
int main(){
	init();
	int adc_reading_front;
	int adc_reading_right;
	
	while(true){
		adc_reading_front = read_analog(0);
		adc_reading_right = read_analog(1);
		distance_measure(distance, adc_reading_front, adc_reading_right);
	}
