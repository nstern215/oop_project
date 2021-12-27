#pragma once

#include "BoardItem.h"

class Teleport : public BoardItem {

public:

	Teleport(Location pairLocation);

	Location launch();

protected:

private:

	Location m_pairLocation;

};