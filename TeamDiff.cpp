#include "TeamDiff.h"

TeamDiff::TeamDiff()
{
	m_team = "";
	
	m_differential = 0;
	
}

void TeamDiff::setTeam(std::string team)
{
	
	m_team = team;
	
}

std::string TeamDiff::getTeam()
{
	
	return m_team;
	
}

void TeamDiff::setDiff(int diff)
{
	
	m_differential = diff;
	
}

int TeamDiff::getDiff()
{
	
	return m_differential;
	
}
