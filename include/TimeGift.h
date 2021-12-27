#pragma once

#include "Gift.h"

class TimeGift : public Gift {

public:

	virtual void useGift(Controller& controller);

protected:

private:

	int m_timeInSeconds;

};