#pragma once

#include "Characters.h"

class King : public Characters {

public:

	King(Location location = {0,0});

private:

	bool gotToThrone(Location& location);

	bool m_throne;

};