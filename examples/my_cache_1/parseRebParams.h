#ifndef PARSEREBPARAMS_H
#define PARSEREBPARAMS_H

void parseParams_LruTailAge(char *LTAparams, int *interval, double *tailAgeDifferenceRatio, 
		int *minTailAgeDifference, unsigned int *minSlabs,int *numSlabsFreeMem, int *slabProjectionLength);

void parseParams_MarginalHits(char *MHparams, int *interval, double *movingAverageParam,
		unsigned int *minSlabs, unsigned int *maxFreeMemSlabs);

void parseParams_HitsPerSlab(char *HPSParams,int *interval,int *minDiff, unsigned int *minSlabs,
			  double *diffRatio, int *numSlabsFreeMem,int *minLruTailAge,int *maxLruTailAge);

void parseParams_FreeMem(char *FMParams,int *interval,unsigned int *minSlabs,
		int *numSlabsFreeMem, size_t *maxUnAllocatedSlabs);

#endif
