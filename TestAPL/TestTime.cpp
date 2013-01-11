//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
#include <boost/test/unit_test.hpp>
#include <APLTestTools/TestHelpers.h>
#include <iostream>

#include <APL/Types.h>
#include <APL/Thread.h>
#include <APL/TimeSource.h>
#include <APL/Util.h>

#include <APLTestTools/Timeout.h>
#include <APLTestTools/StopWatch.h>

#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace apl;

BOOST_AUTO_TEST_SUITE(TimeoutTests)

BOOST_AUTO_TEST_CASE(TimeoutCorrectlyNotExpired)
{
	//create a timeout of 1 millisecond
	Timeout to(milliseconds(1000));

	//check that the timeout starts out unexpired
	BOOST_REQUIRE_EQUAL(to.IsExpired(), false);
	BOOST_REQUIRE(to.Remaining() > milliseconds(1));
}

BOOST_AUTO_TEST_CASE(TimeoutCorrectlyExpires)
{
	//create a timeout of 1 millisecond
	Timeout to(milliseconds(1));

	std::this_thread::sleep_for(milliseconds(10));

	//check that the timeout starts out unexpired
	BOOST_REQUIRE(to.IsExpired());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(StopWatchTests)

BOOST_AUTO_TEST_CASE(BasicTest)
{
	StopWatch sw;

	BOOST_REQUIRE(sw.Elapsed(false) <= milliseconds(100));

	//sleep for 5 millis
	std::this_thread::sleep_for(milliseconds(100));

	//make sure the stopwatch recorded atleast 5 millis elapsed (override default bool)
	BOOST_REQUIRE(sw.Elapsed(false) >= milliseconds(100));	
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TimeManagerTests)
BOOST_AUTO_TEST_CASE(TimeSourceSystemOffsetTest)
{

	TimeSourceSystemOffset time;
	high_resolution_clock::time_point base = time.GetUTC();
	time.SetTime(base + milliseconds(5000));
	BOOST_REQUIRE(time.GetUTC() >= base + milliseconds(5000));
}
BOOST_AUTO_TEST_CASE(TimeSourceSystemOffsetTestNeg)
{

	TimeSourceSystemOffset time;
	high_resolution_clock::time_point base = time.GetUTC();
	time.SetTime(base - milliseconds(5000));
	BOOST_REQUIRE(time.GetUTC() >= base - milliseconds(5000));
}
BOOST_AUTO_TEST_SUITE_END()
