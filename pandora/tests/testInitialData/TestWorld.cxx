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

#include "TestWorld.hxx"

#include "Raster.hxx"
#include "Point2D.hxx"
#include "Exceptions.hxx"

#include "TestAgent.hxx"

#include <assert.h>
#include <iostream>

namespace Test
{

TestWorld::TestWorld( const Engine::Simulation & sim ) : World(sim, 4, true, "data/test.h5")
{
}

TestWorld::~TestWorld()
{
}

void TestWorld::stepAgents()
{
	if(_simulation.getId()==0)
	{
		assert(_agents.size()==1);
		TestAgent * agent = (TestAgent*)(*_agents.begin());
		assert(agent->getId()=="test_0");
	}
	Engine::Point2D<int> index(0,0);
	for(index._x=_boundaries._origin._x; index._x<_boundaries._origin._x+_boundaries._size._x; index._x++)		
	{
		for(index._y=_boundaries._origin._y; index._y<_boundaries._origin._y+_boundaries._size._y; index._y++)			
		{
			assert(getValue("test", index)==_simulation.getId()+1);
		}
	}
}

void TestWorld::createRasters()
{	
	registerDynamicRaster("test", false);
	getDynamicRaster("test").setInitValues(0, 5, 0);

	// at least each cell has value 1
	Engine::Point2D<int> index(0,0);
	for(index._x=_boundaries._origin._x; index._x<_boundaries._origin._x+_boundaries._size._x; index._x++)		
	{
		for(index._y=_boundaries._origin._y; index._y<_boundaries._origin._y+_boundaries._size._y; index._y++)			
		{
			//std::cout << _id << " setting value: " << index << " with boundaries: " << _boundaries << " at pos: " << index-_overlapBoundaries._origin << std::endl;
			setMaxValue("test", index, _simulation.getId()+1);
		}
	}
	updateRasterToMaxValues("test");
}

void TestWorld::createAgents()
{
	if(_simulation.getId()==0)
	{
		TestAgent * agent = new TestAgent("test_0");
		agent->setPosition(Engine::Point2D<int>(31,31));
		addAgent(agent);
		return;
	}
}

} // namespace Test 

