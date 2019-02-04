
#include "gtest/gtest.h"

#include "insertionsort.h"
#include "utils.h"

using namespace cs;

class Sort : public testing::TestWithParam<void (*)(
                 std::vector<int>::iterator, std::vector<int>::iterator)> {};

TEST_P(Sort, SortEmptyRange) {
  auto arange = make_random_range<int>(0);
  GetParam()(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

TEST_P(Sort, SortSingletonRange) {
  auto arange = make_random_range<int>(1);
  GetParam()(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

TEST_P(Sort, SortSmallRange) {
  auto arange = make_random_range<int>(8);
  GetParam()(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

TEST_P(Sort, SortLargeRange) {
  auto arange = make_random_range<int>(1024);
  GetParam()(arange.begin(), arange.end());
  EXPECT_TRUE(std::is_sorted(arange.begin(), arange.end()));
}

INSTANTIATE_TEST_CASE_P(
    Insertion, Sort,
    testing::Values(insertion_sort<std::vector<int>::iterator>));
