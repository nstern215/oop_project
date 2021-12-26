#pragma once

#include "ClockMode.h"
#include <ctime>
#include <SFML.hpp>

class Clock {
public:

	Clock();
	~Clock();

	void addTime(int seconds);
	void setTime(int seconds);
	void stopTimer();
	void resetStopWatch();
	int stopWatch();
	int getTimeInSeconds();
	ClockMode getMode();


private:

	sf::Clock m_clock;

	ClockMode m_mode;

};