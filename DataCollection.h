#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H
#include "Team.h"
#include "Stats.h"
#include <cmath>
#include <fstream>
#include <iostream>


class DataCollection
{

private:
	
	std::ifstream m_inFile;
	std::string m_fileName;
	Team** overall;

public:	
	void buildPointDifferential(Team& team);
	double calculateHomeWinPercent(Team& team);
	double calculateAwayWinPercent(Team& team);
	int calculateDiffOfYear(Team& homeTeam, Team& awayTeam);
	double calculateDiffOverall(Team& homeTeam1, Team& awayTeam1, Team& homeTeam2, Team& awayTeam2, Team& homeTeam3, Team& awayTeam3, Team& homeTeam4, Team& awayTeam4);


	DataCollection(std::string fileName);
	
	~DataCollection();
	
	void run();
	
	
};

#endif
