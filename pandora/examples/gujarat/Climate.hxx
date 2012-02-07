
#ifndef __Climate_hxx__
#define __Climate_hxx__

#include <boost/random.hpp>

namespace Gujarat
{

enum Seasons
{
	HOTWET = 0,
	COLDDRY = 1,
	HOTDRY = 2
};

class GujaratConfig;

class Climate
{	
	typedef boost::mt19937 RandomEngine;
	RandomEngine _randomGenerator;
	Seasons _currentSeason;
	//distrib rainDistribs[Seasons*2] = {m1,d1,m2,d2,m3,d3}; // PENDENT, rebre les mitjanes-desv
	float   _currentRain; // mm on heigth of rain
	//Moistures    moistureLevel;
	//Temperatures temperatureLevel;	
	boost::variate_generator< RandomEngine, boost::uniform_real<> > _uniformDistribution;

	const GujaratConfig & _config;

public:
	Climate( const GujaratConfig & config );
	virtual ~Climate();

	void step();	
	float getMeanAnnualRain() const;
	const float & getRain() const;
	const Seasons & getSeason() const;

	void advanceSeason();
};

} // namespace Gujarat

#endif // __Climate_hxx__
