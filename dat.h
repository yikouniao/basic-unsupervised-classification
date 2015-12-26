#pragma once
#include <array>
#include <vector>
#include <iostream>
#include <fstream>

enum Pattern {PATTERN_UNKNOWN = -1,
                  PATTERN_A, PATTERN_B, PATTERN_C, PATTERN_CNT};

using XY = std::array<double, 2>; // pure two-dimensional data

XY& operator+= (XY& xy1, const XY& xy2);
XY& operator/= (XY& xy1, const int n);

class SingleDat { // two-dimensional data with pattern
 public:
  XY xy_;
  Pattern pattern_;

  SingleDat();
  SingleDat(const std::array<double, 2>& xy,
            Pattern pattern = PATTERN_UNKNOWN);
  ~SingleDat();
};

template <size_t pattern_num>
using PatternCenter = std::array<XY, pattern_num>; // the center of patterns

std::ostream& operator<< (std::ostream& out, const PatternCenter<PATTERN_CNT>& c);

bool operator!= (const PatternCenter<PATTERN_CNT>& a,
                 const PatternCenter<PATTERN_CNT>& b);

double DatDistance(const SingleDat& a, const SingleDat& b);
double DatDistance(const SingleDat& a, const XY& b);
double DatDistance(const XY& a, const SingleDat& b);
double DatDistance(const XY& a, const XY& b);

using Dat = std::vector<SingleDat>; // a vector of data

void GetDat(Dat& dat, char* f_name); // Get a Dat from file
std::ostream& operator<< (std::ostream& out, const Dat& dat);
std::ostream& operator<< (std::ostream& out, const Pattern& pattern);