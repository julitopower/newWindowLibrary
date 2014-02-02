/*
 * Simple Raspberry Pi OpenGl-ES window tests application 
 * Copyright (C) 2013-2014, Julio Delgado <julio.delgadomangas@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This file is used to launch all the tests using cppUnit
 */
#include <iostream>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>

int main(int argc, char** argv) {
	// Enable reporting
	CppUnit::TestResult controller;

 	 //--- Add a listener that colllects test result
	CppUnit::TestResultCollector result;
  	controller.addListener( &result );        

	//--- Add a listener that print dots as test run.
	CppUnit::BriefTestProgressListener progress;
  
	controller.addListener( &progress );      	
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry & registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest( registry.makeTest() );
	runner.run(controller);
	return 0;
}
