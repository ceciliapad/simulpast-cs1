/*
 * Copyright (c) 2012
 * COMPUTER APPLICATIONSN IN SCIENCE & ENGINEERING
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

#ifndef __TestAgentA_hxx__
#define __TestAgentA_hxx__

#include "Agent.hxx"
#include <string>

namespace Test
{

class TestAgentA: public Engine::Agent
{	
	int _testValueA; // MpiAttribute
	std::string _testId; // MpiAttribute

	void move();
	void serialize();

public:
	TestAgentA( const std::string & id );
	virtual ~TestAgentA();
	
	void step();
	const std::string & getTestId();
	const int & getTestValueA();
	
	// Mpi related
	TestAgentA( void * package );
	void * fillPackage();
};

} // namespace Test

#endif // __TestAgentA_hxx__

