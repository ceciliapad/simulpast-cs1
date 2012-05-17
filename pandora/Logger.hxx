
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

#ifndef __Logger_hxx__
#define __Logger_hxx__

#include <map>
#include <fstream>

namespace Engine
{

class Logger
{
	typedef std::map <std::string, std::ofstream *> FilesMap;
	static Logger * _instance;

	FilesMap _files;
protected:
	Logger();

public:
	static Logger & instance();
	virtual ~Logger();
	// message to file
	std::ofstream & log( const std::string & fileName );
};

} // namespace  Engine


#endif // __Logger_hxx__
