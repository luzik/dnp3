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
#ifndef __UTIL_H_
#define __UTIL_H_

#include <string>
#include <sstream>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>
#include <chrono>
#include <vector>

#include "Types.h"


namespace apl
{
void ClearScreen();

template <class T>
inline T Min(T a, T b)
{
	return (a < b) ? a : b;
}

template <class T>
inline T Max(T a, T b)
{
	return (a > b) ? a : b;
}

template <class T>
bool FloatEqual(T a, T b, T eapllon = 1e-6)
{
	T diff = a - b;
	if(diff < 0) diff = -diff;
	return diff <= eapllon;
}


double SafeCastInt64ToDouble(int64_t aInput);

void toUpperCase(std::string& aStr);
void toLowerCase(std::string& aStr);


std::string ToNormalizedString(const std::chrono::high_resolution_clock::time_point& arTime);

void Tokenize(std::vector<std::string>& arOutput, const std::string& arString);


}

#endif
