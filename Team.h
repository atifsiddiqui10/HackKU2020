#ifndef TEAM_H
#define TEAM_H
#include "TeamComp.h"
#include "TeamDiff.h"
#include <fstream>
#include <string>


class Team
{
	
private:

	TeamComp* m_theTeamComp;
	TeamDiff* m_theTeamDiff;
	int homeDiff;
	int awayDiff;
	std::string m_teamName;
		

public:

	Team();
	
	~Team();
	
	void setTeamName(std::string teamName);
	
	std::string getTeamName();
	
	TeamComp*& getTeamComp();
	
	TeamDiff*& getTeamDiff();
	
	int getHomeDiff();
	
	int getAwayDiff();
	
	void setHomeDiff(int diff);
	
	void setAwayDiff(int diff);

	
};


#endif
