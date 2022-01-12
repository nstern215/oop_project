#include "Clock.h"

Clock::Clock(ClockMode mode, int seconds) :
	m_mode(mode),
	m_remainTime(seconds)
{
}

Clock::~Clock()
{
}

void Clock::addTime(float seconds)
{
	m_remainTime += seconds;
}

void Clock::setTime(float seconds)
{
	m_remainTime = seconds;
}

void Clock::resumeClock(float seconds)
{
	m_remainTime = seconds;
	m_clock.restart();
}

float Clock::stopClock()
{
	return updateTime();
}

float Clock::getTimeInSeconds() const
{
	return m_clock.getElapsedTime().asSeconds();
}

ClockMode Clock::getMode() const
{
	return m_mode;
}

void Clock::reset()
{
	resumeClock(0);
}

void Clock::setMode(ClockMode mode)
{
	m_mode = mode;
}

float Clock::updateTime()
{
	const float elapsed = m_clock.restart().asSeconds();

	if (m_mode == 0)
		m_remainTime += elapsed;
	else
		m_remainTime -= elapsed;

	if (m_remainTime < 0)
		m_remainTime = 0;

	return elapsed;
}

std::string Clock::toString() const
{
	int current = m_remainTime;

	const int hours = current / (60 * 60);
	current %= (60 * 60);
	const int minutes = current / 60;
	current %= 60;

	return normalTimeValue(hours) + ":" + normalTimeValue(minutes) + ":" + normalTimeValue(current);
}

std::string Clock::normalTimeValue(int value) const
{
	if (value == 0)
		return "00";

	if (value < 10)
		return  "0" + std::to_string(value);

	return std::to_string(value);
}

float Clock::getRemainTime() const
{
	return m_remainTime;
}
