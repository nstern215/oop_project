#pragma once

#include "ClockMode.h"
#include <ctime>
#include <SFML/Graphics.hpp>

class Clock {
public:

	Clock(ClockMode mode = STOPWATCH, int seconds = 0);
	~Clock();

	void addTime(float seconds);
	void setTime(float seconds);
	float stopClock();
	void reset(float seconds = 0);
	void resumeClock(float seconds);
	float getTimeInSeconds() const;
	ClockMode getMode() const;
	void setMode(ClockMode mode);
	float getRemainTime() const;
	float updateTime();
	std::string toString() const;

private:
	sf::Clock m_clock;
	ClockMode m_mode;
	float m_remainTime;
	std::string normalTimeValue(int value) const;
};