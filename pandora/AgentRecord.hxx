
/*
 * Copyright (c) 2012
 * COMPUTER APPLICATIONS IN SCIENCE & ENGINEERING
 * BARCELONA SUPERCOMPUTING CENTRE - CENTRO NACIONAL DE SUPERCOMPUTACIÓN
 * http://www.bsc.es

 * This file is part of Pandora Library. This library is free software; 
 * you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation;
 * either version 3.0 of the License, or (at your option) any later version.
 * 
 * Pandora is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef __AgentRecord_hxx__
#define __AgentRecord_hxx__

#include <map>
#include <vector>
#include <string>

namespace Engine
{

class AgentRecord
{
	typedef std::vector<int> ValuesVector;
	std::string _id;
public:
	typedef std::map<std::string, ValuesVector > StatesMap;
	// total number of steps in simulation (not agent life)
	int _numSteps;
	StatesMap _states;
public:
	AgentRecord( const std::string & id, int numSteps );
	virtual ~AgentRecord();
	// TODO x and y must be integers or strings?
	void addState( int numStep, const std::string & id, int value );
	int getState( int numStep, const std::string & key );
	std::string getCompleteState( int numStep );

	StatesMap::iterator beginStates();
	StatesMap::iterator endStates();
};

} // namespace Engine

#endif // __AgentRecord_hxx__

