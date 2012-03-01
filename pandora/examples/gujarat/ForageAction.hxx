#ifndef __ForageAction_hxx__
#define __ForageAction_hxx__

#include "Action.hxx"
#include "Sector.hxx"
#include "Point2D.hxx"
#include "World.hxx"

namespace Gujarat
{

class GujaratAgent;

class ForageAction : public Action
{
private:

	Sector*		_forageArea;

	int		doWalk( Engine::Point2D<int>& start, 
				double maxDist,
				Engine::World* world );

public:
	ForageAction( Sector* loc );
	virtual ~ForageAction();

	void	execute( GujaratAgent& agent );
	int	getTimeNeeded() { return 1; }
};

}

#endif // ForageAction.hxx