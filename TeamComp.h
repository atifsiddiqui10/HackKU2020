#ifndef TEAMCOMP_H
#define TEAMCOMP_H
#include <string>

class TeamComp
{

private:
	
	std::string m_otherTeam;
	char m_ha;
	int m_teamScore;
	int m_otherTeamScore;
	
	
public:
	
	TeamComp();
	
	TeamComp(std::string otherTeam, char ha, int teamScore, int otherTeamScore);
	
	~TeamComp();
	
	void setOtherTeam(std::string otherTeam);
	
	std::string getOtherTeam();
	
	void setHa(char ha);
	
	char getHa();
	
	void setTeamScore(int teamScore);
	
	int getTeamScore();
	
	void setOtherTeamScore(int otherTeamScore);
	
	int getOtherTeamScore();
	
	
};


#endif
