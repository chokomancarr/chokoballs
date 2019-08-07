#pragma once
#include "defines.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class ChokoBalls;

#define CB_OBJECT(nm) class nm; typedef std::shared_ptr<nm> p ## nm;

CB_OBJECT(Object)

CB_OBJECT(World)

#undef CB_OBJECT

#include "object.hpp"

#include "world.hpp"