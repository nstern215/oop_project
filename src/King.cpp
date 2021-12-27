#include "King.h"

King::King(Location location)
	:Characters(location)
{
	m_throne = false;
}

bool King::gotToThrone(Location& location)
{
	return m_throne;
}
