#include "King.h"

King::King(Location location)
	:Item(location)
{
	m_throne = false;
}

bool King::gotToThrone(Location& location)
{
	return m_throne;
}
