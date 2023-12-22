#include "Creature.h"

void Creature::moveTo(int x, int y)
{
	m_location.setPoint(x, y);
}
std::ostream& operator<<(std::ostream& out, const Creature& creature)
{
	out << creature.m_name << " is at " << creature.m_location;
	return out;
}
