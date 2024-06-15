#include "folly/init/Init.h"
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <sstream>
#include "parseRebParams.h"

void parseParams_LruTailAge(char *LTAparams, int *interval, double *tailAgeDifferenceRatio, 
		int *minTailAgeDifference, unsigned int *minSlabs,int *numSlabsFreeMem, int *slabProjectionLength){
  std::string str(LTAparams);
  std::string params = str;

  if (params == "default") return;

  char delimiter = ',';
  std::stringstream ss(params);
  std::string token;

  int i = 0;
  while (std::getline(ss, token, delimiter)) {
	if (i == 0) *interval = std::stoi(token); 
	else if (i==1) *tailAgeDifferenceRatio = std::stod(token);
	else if (i==2) *minTailAgeDifference = std::stoi(token);
	else if (i==3) *minSlabs = std::stoi(token);
	else if (i==4) *numSlabsFreeMem = std::stoi(token);
	else if (i==5) *slabProjectionLength = std::stoi(token);
	i += 1;	
  }
}

void parseParams_MarginalHits(char *MHparams, int *interval, double *movingAverageParam,
		unsigned int *minSlabs, unsigned int *maxFreeMemSlabs){
  
  std::string str(MHparams);
  std::string params = str;

  if (params == "default") return;
 
  char delimiter = ',';
  std::stringstream ss(params);
  std::string token;

  int i = 0;
  while (std::getline(ss, token, delimiter)) {
	if (i == 0) *interval = std::stoi(token); 
	else if (i==1) *movingAverageParam = std::stod(token);
	else if (i==2) *minSlabs = std::stoi(token);
	else if (i==3) *maxFreeMemSlabs = std::stoi(token);
	i += 1;	
  }

}

void parseParams_HitsPerSlab(char *HPSParams,int *interval,int *minDiff,unsigned int *minSlabs,
			  double *diffRatio, int *numSlabsFreeMem,int *minLruTailAge,int *maxLruTailAge)
{
  std::string str(HPSParams);
  std::string params = str;

  if (params == "default") return;

  char delimiter = ',';
  std::stringstream ss(params);
  std::string token;

  int i = 0;
  while (std::getline(ss, token, delimiter)) {
	if (i == 0) *interval = std::stoi(token); 
	else if (i == 1) *minDiff = std::stoi(token); 
	else if (i == 2) *minSlabs = std::stoi(token); 
	else if (i==3) *diffRatio = std::stod(token);
	else if (i==4) *numSlabsFreeMem = std::stoi(token);
	else if (i==5) *minLruTailAge = std::stoi(token);
	else if (i==6) *maxLruTailAge = std::stoi(token);
	i += 1;	
  }
}


void parseParams_FreeMem(char *FMParams,int *interval,unsigned int *minSlabs,
		int *numSlabsFreeMem, size_t *maxUnAllocatedSlabs)
{
  std::string str(FMParams);
  std::string params = str;

  if (params == "default") return;
  
  char delimiter = ',';

  std::stringstream ss(params);
  std::string token;

  int i = 0;
  while (std::getline(ss, token, delimiter)) {
	if (i == 0) *interval = std::stoi(token);
	else if (i == 1) *minSlabs = std::stoi(token);
	else if (i == 3) *numSlabsFreeMem = std::stoi(token);
	else if (i == 4) *maxUnAllocatedSlabs = std::stoi(token);
	i += 1;
  }
}
