#include <iostream>
#include <Time.h>
using namespace std;

#include "Timer.h"

// Les constructeurs
Timer::Timer(int delay){
	time = clock();
	this->delay = delay;
};

bool Timer::isReady(){
	bool answer = false;
	if (clock() >= time + delay){
		answer = true;
		time = clock();
	}
	return answer;
};
