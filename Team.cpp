#include "Team.h"

Team::Team()
{
	
	m_theTeamComp = new TeamComp[10];
	m_theTeamDiff = new TeamDiff[5];
	
	
}

Team::~Team()
{
	
	delete m_theTeamComp;
	delete m_theTeamDiff;
	
}

int Team::getAwayDiff()
{
	
	return awayDiff;
	
}

int Team::getHomeDiff()
{
	
	return homeDiff;
	
}

void Team::setAwayDiff(int diff)
{
	
	awayDiff = diff;
	
}
void Team::setHomeDiff(int diff)
{
	
	homeDiff = diff;
	
}


void Team::setTeamName(std::string teamName)
{
	
	m_teamName = teamName;
	
	
}

std::string Team::getTeamName()
{
	
	return m_teamName;	
	
}

TeamComp*& Team::getTeamComp()
{
	
	return m_theTeamComp;
	
}

TeamDiff*& Team::getTeamDiff()
{
	
	return m_theTeamDiff;
	
}
