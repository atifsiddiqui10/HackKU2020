#include "TeamComp.h"

TeamComp::TeamComp()
{
	
	
}


TeamComp::~TeamComp()
{
	
	
	
}
TeamComp::TeamComp(std::string otherTeam, char ha, int teamScore, int otherTeamScore)
{
	
	m_otherTeam = otherTeam;
	m_ha = ha;
	m_teamScore = teamScore;
	m_otherTeamScore = otherTeamScore;	
	
}

void TeamComp::setOtherTeam(std::string otherTeam)
{
	
	m_otherTeam = otherTeam;
	
}

std::string TeamComp::getOtherTeam()
{
	
	return m_otherTeam;
	
}

void TeamComp::setHa(char ha)
{
	
	m_ha = ha;
		
}

char TeamComp::getHa()
{
	
	return m_ha;
	
}

void TeamComp::setTeamScore(int teamScore)
{
	
	m_teamScore = teamScore;
	
}

int TeamComp::getTeamScore()
{
	
	return m_teamScore;
	
}

void TeamComp::setOtherTeamScore(int otherTeamScore)
{
	
	m_otherTeamScore = otherTeamScore;
	
}

int TeamComp::getOtherTeamScore()
{
	
	return m_otherTeamScore;
	
}
