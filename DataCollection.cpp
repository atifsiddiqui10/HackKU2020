#include "DataCollection.h"

void DataCollection::buildPointDifferential(Team& team)
{
		for(int i = 0; i < 10; i++)
	{
		bool alreadyInDiff = false;
			
		for(int j = 0; j < 5; j++)
		{
			if(team.getTeamComp()[i].getOtherTeam() == team.getTeamDiff()[j].getTeam())
			{
				
				alreadyInDiff = true;
				
				int diff = team.getTeamComp()[i].getTeamScore() - team.getTeamComp()[i].getOtherTeamScore();
				
				team.getTeamDiff()[j].setDiff(team.getTeamDiff()[j].getDiff() + diff);
				
			}
			
		}
		if(!alreadyInDiff)
		{
			int j = 0;
			while(team.getTeamDiff()[j].getTeam() != "")
			{
	
				j++;
				
			}
			
			team.getTeamDiff()[j].setTeam(team.getTeamComp()[i].getOtherTeam());
			team.getTeamDiff()[j].setDiff(team.getTeamComp()[i].getTeamScore() - team.getTeamComp()[i].getOtherTeamScore());
		}
		
				
	}
}

double DataCollection::calculateHomeWinPercent(Team& team)
{
	int wins = 0;
	
	for(int i = 0; i < 10; i++)
	{
		
		if(team.getTeamComp()[i].getHa() == 'H')
		{
			
			if(team.getTeamComp()[i].getTeamScore() > team.getTeamComp()[i].getOtherTeamScore())
			{
				
					wins++;
				
			}
						
		}
		
	}
	
return (double)wins/10.0;
}

double DataCollection::calculateAwayWinPercent(Team& team)
{
	int wins = 0;
	
	for(int i = 0; i < 10; i++)
	{
		
		if(team.getTeamComp()[i].getHa() == 'A')
		{
			
			if(team.getTeamComp()[i].getTeamScore() > team.getTeamComp()[i].getOtherTeamScore())
			{
				
					wins++;
				
			}
						
		}
			}
	
 return (double)wins/10.0;
}

int DataCollection::calculateDiffOfYear(Team& homeTeam, Team& awayTeam)
{
	
	int firstDif = 0;
	
	for(int i = 0; i < 5; i++)
	{

		if(homeTeam.getTeamDiff()[i].getTeam() == awayTeam.getTeamName())
		{
			firstDif = homeTeam.getTeamDiff()[i].getDiff();
			break;
			
		}
		
	}
	
	
	
	return firstDif + homeTeam.getHomeDiff() + awayTeam.getAwayDiff();
	
}
double DataCollection::calculateDiffOverall(Team& homeTeam1, Team& awayTeam1, Team& homeTeam2, Team& awayTeam2, Team& homeTeam3, Team& awayTeam3, Team& homeTeam4, Team& awayTeam4)
{

	return (0.0625+ (.004167)) * (double) calculateDiffOfYear(homeTeam1, awayTeam1) + (0.125+ (.0833333)) * (double) calculateDiffOfYear(homeTeam2, awayTeam2) + (0.25+ (.01666)) * (double) calculateDiffOfYear(homeTeam3, awayTeam3) + (0.5+ (.03333)) * (double) calculateDiffOfYear(homeTeam4, awayTeam4); 
	
}

DataCollection::DataCollection(std::string fileName)
{
	
	m_fileName = fileName;
	
}

DataCollection::~DataCollection()
{
	
}

void DataCollection::run()
{
	
	std::string year = "";
	
		m_inFile.open(m_fileName);
	
	if(!m_inFile.is_open())
	{
		
		std::cout << "File could not be opened!" << '\n';
		
		exit(0);
		
	}
	
	overall = new Team*[4];
	for(int i = 0; i < 4; i++)
	{
		
		overall[i] = new Team[6];
		
	}
	
	for(int l = 0; l < 4; l++)
	{
		m_inFile >> year;
		
		std::cout << year << '\n';
	
	
	std::string teamName = "";
	

	
	Team* m_teamList = new Team[6];

	
	for(int i = 0; i < 6; i++)
	{
		m_inFile >> teamName;
		
		m_teamList[i].setTeamName(teamName);
		
		std::cout << m_teamList[i].getTeamName()<<std::endl;
		
		int home = 0;
		
		int away = 0;
			
		
		for(int j = 0; j < 10; j++)
		{
			
			std::string otherTeam = "";
			
			m_inFile >> otherTeam;
			
			char ha = '\0';
			
			m_inFile >> ha;
			
			int points = -1;
			
			m_inFile >> points;
			
			if(ha == 'H')
			{
				
				home += points;
				
			}
			
			if(ha == 'A')
			{
				
				away += points;
				
			}
			
			int otherPoints = -1;	
				
			m_inFile >> otherPoints;
			
			if(ha == 'H')
			{
				
				home -= points;
				
			}
				
			if(ha == 'A')
			{
				
				away -= points;
				
			}
			
			m_teamList[i].setHomeDiff(home);
			m_teamList[i].setAwayDiff(away);
			m_teamList[i].getTeamComp()[j].setOtherTeam(otherTeam);
			
			std::cout<<m_teamList[i].getTeamComp()[j].getOtherTeam() << ' ';
			
			m_teamList[i].getTeamComp()[j].setHa(ha);
			
			std::cout<<m_teamList[i].getTeamComp()[j].getHa() << ' ';
			
			m_teamList[i].getTeamComp()[j].setTeamScore(points);
			
			std::cout<<m_teamList[i].getTeamComp()[j].getTeamScore() << ' ';
			
			m_teamList[i].getTeamComp()[j].setOtherTeamScore(otherPoints);
			
			std::cout<<m_teamList[i].getTeamComp()[j].getOtherTeamScore() << std::endl;
			
		
			
		}
			
			std::cout << calculateHomeWinPercent(m_teamList[i]) << std::endl;
			
			std::cout << calculateAwayWinPercent(m_teamList[i]) << std::endl;			
		
			buildPointDifferential(m_teamList[i]);
			
			for(int j = 0; j < 5; j++)
			{
				
				std::cout << m_teamList[i].getTeamDiff()[j].getTeam() << ' ';
				std::cout << m_teamList[i].getTeamDiff()[j].getDiff() << std::endl;
				
			}
			
			std::cout<< std::endl;
		
	
	}
	overall[l] = m_teamList;

	}
	
	std::cout << "Predicted Outcomes of 2019/2020 Season" <<'\n';
	
	for(int i = 0; i < 6; i++)
	{
	
		
		for(int j = 0; j < 6; j++)
		{
			
			if(j == i)
			{
				
				j++;
				
			}
			std::cout << overall[0][i].getTeamName() << " vs " << overall[0][j].getTeamName() << ' ';
			std::cout << round(calculateDiffOverall(overall[0][i],overall[0][j],overall[1][i],overall[1][j],overall[2][i],overall[2][j],overall[3][i],overall[3][j]));
			std::cout << std::endl;
			
			if(i == 5 && j == 4)
			{
				
				break;
				
			}
			
		}
		
	}
	
	std::cout << "END"  << std::endl;
}
