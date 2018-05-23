#include <stdio.h>
#include <time.h>
#include "E101.h"

int distance = 175; //Distance from wall
int adjustDistanceLeft = 100; //When robot moves too close to the left wall
int adjustDistanceRight = 300; //When robot moves too close to the right wall
int slow_speed_left = 30; //Slow speed for left wheel must be different becuase of power differences
int slow_speed_right = 20;
int norm_speed_left = 50; //Normal speed of wheels are different
int norm_speed_right = 40;
int adjust_speed_left = 45;
int adjust_speed_right = 35;
int off_speed = 0; //wheels are off

void adjust_left(int norm_speed_left, int adjust_speed_right, int off_speed){
	set_motor(2, norm_speed_left); //Left wheel
	set_motor(1, adjust_speed_right); //Right wheel
	sleep1(0,500);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
}

void turn_left(int norm_speed_right, int slow_speed_left, int off_speed){
	set_motor(2, slow_speed_left); //Left wheel
	set_motor(1, norm_speed_right); //Right wheel
	sleep1(1, 0);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
}

void turn_right(int norm_speed_left, int slow_speed_right, int off_speed){
	set_motor(2, norm_speed_left); //Left wheel
	set_motor(1, slow_speed_right); //Right wheel
	sleep1(1, 0);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
}
	
void straight(int norm_speed_left, int norm_speed_right, int off_speed){
	set_motor(2, norm_speed_left); //Left wheel
	set_motor(1, norm_speed_right); //Right wheel
	sleep1(1, 0);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
}

void adjust_right(int norm_speed_right, int adjust_speed_left, int off_speed){
	set_motor(2, adjust_speed_left); //Left wheel
	set_motor(1, norm_speed_right); //Right wheel
	sleep1(0,500);
	set_motor(2, off_speed); //Left wheel
	set_motor(1, off_speed); //Right wheel
}

void distance_measure(double distance, int adc_reading_front, int adc_reading_right){
	if(adc_reading_right > adjustDistanceRight && adc_reading_front < distance){
			adjust_right(norm_speed_right, slow_speed_left, off_speed);
	}
	if(adc_reading_right > distance && adc_reading_right > adjustDistanceLeft && adc_reading_front < distance){
			adjust_left(norm_speed_left, slow_speed_right, off_speed);
	} 
//	if(adc_reading_front > distance && adc_reading_right > distance){
//			turn_left(norm_speed_left, slow_speed_right, off_speed);
//	}
//	if(adc_reading_front < distance && adc_reading_right > distance){
//			straight(norm_speed_left, norm_speed_right, off_speed);
//	}
//	if(adc_reading_front > distance && adc_reading_right < distance){
//			turn_right(int norm_speed_right, int slow_speed_left, int off_speed);
//	}
//	if(adc_reading_front < distance && adc_readreading_right < distance){
//			turn_right(int norm_speed_right, int slow_speed_left, int off_speed);
//	}
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
}
