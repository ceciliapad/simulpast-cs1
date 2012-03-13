
// this stub code is used to compile cassandra against pandora
// in simulations, the MPI code is generated by a script

#include "MpiFactory.hxx"

namespace Engine
{
class Agent;

void MpiFactory::registerTypes()
{
}

Engine::Agent * MpiFactory::createAndFillAgent( const std::string & type, void * package )
{
	return 0;
}

void * MpiFactory::createDefaultPackage( const std::string & type )
{
	return 0;
}

} // namespace Engine