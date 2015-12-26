#include "dat.h"
#include <cmath>

using namespace std;

XY& operator+= (XY& xy1, const XY& xy2) {
  xy1[0] += xy2[0];
  xy1[1] += xy2[1];
  return xy1;
}

XY& operator/= (XY& xy1, const int n) {
  xy1[0] /= n;
  xy1[1] /= n;
  return xy1;
}

SingleDat::SingleDat() : xy_({0, 0}), pattern_(PATTERN_UNKNOWN) {}

SingleDat::SingleDat(const array<double, 2>& xy, Pattern pattern)
    : xy_(xy), pattern_(pattern) {}

SingleDat::~SingleDat() {}

ostream& operator<< (ostream& out, const PatternCenter<PATTERN_CNT>& c) {
  cout << "\nCenters of patterns:\n";
  for (size_t i = 0; i < PATTERN_CNT; ++i) {
    cout << c[i][0] << "\t" << c[i][1] << "\t";
    Pattern p{static_cast<Pattern>(i)};
    cout << p << "\n";
  }
  return out;
}

bool operator!= (const PatternCenter<PATTERN_CNT>& a,
                 const PatternCenter<PATTERN_CNT>& b) {
  for (size_t i = 0; i < PATTERN_CNT; ++i) {
    if (a[i] != b[i])
      return true;
  }
  return false;
}

double DatDistance(const SingleDat& a, const SingleDat& b) {
  return sqrt(pow(a.xy_[0] - b.xy_[0], 2) + pow(a.xy_[1] - b.xy_[1], 2));
}

double DatDistance(const SingleDat& a, const XY& b) {
  return sqrt(pow(a.xy_[0] - b[0], 2) + pow(a.xy_[1] - b[1], 2));
}

double DatDistance(const XY& a, const SingleDat& b) {
  return sqrt(pow(a[0] - b.xy_[0], 2) + pow(a[1] - b.xy_[1], 2));
}

double DatDistance(const XY& a, const XY& b) {
  return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

void GetDat(Dat& dat, char* f_name) {
  ifstream f(f_name);
  if (!f)
  {
    cerr << f_name << " could not be opened!\n" << endl;
    exit(1);
  }
  XY xy;
  array<char, 10> c;
  while (1) {
    f.getline(&c[0], 65532, '\t'); // Read x_.
    if (c[0] == '#')
      break;
    xy[0] = atof(&c[0]);
    f.getline(&c[0], 65532, '\n'); // Read y_.
    xy[1] = atof(&c[0]);
    dat.push_back(SingleDat(xy, PATTERN_UNKNOWN));
  } // while (1)
}

ostream& operator<< (ostream& out, const Dat& dat) {
  cout << "\nClassification result:\n";
  for (auto& e : dat) {
    cout << e.xy_[0] << "\t" << e.xy_[1] << "\t" << e.pattern_ << "\n";
  }
  return out;
}

ostream& operator<< (ostream& out, const Pattern& pattern) {
  if (pattern == PATTERN_A) {
    cout << "a";
  } else if (pattern == PATTERN_B) {
    cout << "b";
  } else if (pattern == PATTERN_C) {
   cout << "c";
  } else {
    cout << "unknown";
  }
  return out;
}