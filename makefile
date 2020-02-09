Football: main.o DataCollection.o Team.o TeamComp.o TeamDiff.o
	g++ -g -std=c++11 -Wall main.o DataCollection.o Team.o TeamComp.o TeamDiff.o -o Football
main.o: main.cpp DataCollection.o
	g++ -g -std=c++11 -Wall -c main.cpp
DataCollection.o: DataCollection.h DataCollection.cpp Team.h Stats.h
	g++ -g -std=c++11 -Wall -c DataCollection.cpp
Team.o: Team.h Team.cpp TeamComp.h TeamDiff.h
	g++ -g -std=c++11 -Wall -c Team.cpp
TeamComp.o: TeamComp.h TeamComp.cpp
	g++ -g -std=c++11 -Wall -c TeamComp.cpp
TeamDiff.o: TeamDiff.h TeamDiff.cpp
	g++ -g -std=c++11 -Wall -c TeamDiff.cpp
clean:
	rm *.o Football