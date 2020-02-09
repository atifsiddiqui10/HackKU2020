#ifndef TEAMDIFF_H
#define TEAMDIFF_H
#include <string>

class TeamDiff
{

private:
	
	std::string m_team;
	int m_differential;

public:	

	TeamDiff();
	void setTeam(std::string team);
	std::string getTeam();
	void setDiff(int diff);
	int getDiff();
		
};

#endif
