#pragma once

#include <time.h>
#include <random>

#include "SliderBoard.h"

extern std::default_random_engine generator;

void shuffle(SliderBoard & board, size_t count);
