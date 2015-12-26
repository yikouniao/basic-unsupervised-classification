#include "k-means.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void K_Means(char* f) {
  cout << "\nk-means algorithm\n";
  Dat dat;
  GetDat(dat, f);
  PatternCenter<PATTERN_CNT> dat_center;
  PatternCenter<PATTERN_CNT> new_dat_center;
  // Use current time as seed for random generator.
  std::srand(static_cast<unsigned>(std::time(0)));
  // Initialize the center of patterns with random data.
  for (size_t i = 0; i < PATTERN_CNT; ++i) {
    int rand_var = std::rand() % dat.size();
    new_dat_center[i] = dat[rand_var].xy_;
  }
  // k-means algorithm
  do {
    dat_center = new_dat_center;
    for (auto& e : dat) {
      CalSingDatPattern(e, dat_center);
    }
    CalDatCent(dat, new_dat_center);
  } while (dat_center != new_dat_center);
  cout << dat_center;
  cout << dat;
}

void CalSingDatPattern(SingleDat& a, const PatternCenter<PATTERN_CNT>& c) {
  size_t k = 0, i = 0;
  double min_dist = DatDistance(a, c[0]);
  do {
    double dist = DatDistance(a, c[++i]);
    if (dist < min_dist) {
      min_dist = dist;
      k = i; // c[k] is nearest from a.
    }
  } while (i + 1 < PATTERN_CNT);
  a.pattern_ = static_cast<Pattern>(k);
}

void CalDatCent(const Dat& dat, PatternCenter<PATTERN_CNT>& new_dat_center) {
  new_dat_center.fill(XY{0, 0});
  array<size_t, PATTERN_CNT> n{0};
  for (const auto& e : dat) {
    ++(n[e.pattern_]);
    new_dat_center[e.pattern_] += e.xy_; // sum
  }
  for (size_t i = 0; i < PATTERN_CNT; ++i) {
    new_dat_center[i] /= n[i]; // average
  }
}