
#ifndef __INSERTIONSORT_H
#define __INSERTIONSORT_H

#include <utility>

namespace cs {
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

#endif
