
#include "gtest/gtest.h"

#include <random>

namespace cs {
template <typename T>
std::enable_if_t<std::is_integral_v<T>, std::vector<T>>
make_random_range(size_t n) {
  std::mt19937 generator;
  std::uniform_int_distribution<T> distribution;

  std::vector<T> range(n);
  for (auto &n : range)
    n = distribution(generator);
  return range;
}

template <typename It>
void insertion_sort(It begin, It end) {
  // A null range is already sorted.
  if (begin == end)
    return;

  // The range is partitioned into two ranges: [begin, i[, and ]i, end[. The
  // first range is already sorted.
  for (auto i = begin + 1; i != end; ++i) {
    auto j = begin;
    // Find the place where *i should be inserted into the sorted sequence
    // [begin, i[.
    for (; j != i && *j < *i; ++j)
      ;
    // Insert *i at the right place, shifting all the other element to the right
    // in order to create space for *i.
    for (; j != i; ++j)
      std::swap(*j, *i);
  }
}
}

using namespace cs;

TEST(InsertionSort, SortEmptyRange) {
  auto arange = make_random_range<int>(0);
  insertion_sort(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

TEST(InsertionSort, SortSingletonRange) {
  auto arange = make_random_range<int>(1);
  insertion_sort(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

TEST(InsertionSort, SortSmallRange) {
  auto arange = make_random_range<int>(8);
  insertion_sort(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

TEST(InsertionSort, SortLargeRange) {
  auto arange = make_random_range<int>(1024);
  insertion_sort(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}
