#pragma once
#include "dat.h"

// k-means algorithm
void K_Means(char* f);
// Calculate which pattern a SingleDat belongs to.
void CalSingDatPattern(SingleDat& a, const PatternCenter<PATTERN_CNT>& c);
// Calculate the center of a Dat
void CalDatCent(const Dat& dat, PatternCenter<PATTERN_CNT>& new_dat_center);
