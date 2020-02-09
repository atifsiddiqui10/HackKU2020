#include "DataCollection.h"

/**
	*  @pre argv[] must be valid
	*  @param argv[1] must be a file name in file with the executable
	*  @post Runs executive class member object with run method
	*  @return 0 to terminate program"
	*/
int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
     DataCollection data(argv[1]);
     data.run();
  }

  return(0);
}

