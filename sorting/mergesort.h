
#ifndef __MERGESORT_H
#define __MERGESORT_H

#include <utility>
#include "utils.h"

namespace cs {
template <typename It>
void merge_combine(It begin, It i, It end) {
  std::vector<typename std::iterator_traits<It>::value_type> left(begin, i),
      right(i, end);

  auto j = left.begin(), e = left.end();
  auto k = right.begin(), f = right.end();

  while (j != e && k != f)
    *begin++ = *j <= *k ? *j++ : *k++;
  while (j != e)
    *begin++ = *j++;
  while (k != f)
    *begin++ = *k++;
}

template <typename It>
void merge_sort(It begin, It end) {
  if (end - begin <= 1)
    return;

  auto i = begin + (end - begin) / 2;
  merge_sort(begin, i);
  merge_sort(i, end);
  merge_combine(begin, i, end);
}
}

#endif
