
#include <utility>

namespace cs {
template <typename It>
void selection_sort(It begin, It end) {
  // A null range is already sorted.
  if (begin == end)
    return;

  // The [begin, end[ range is split into two subranges. The [begin, i[ range is
  // fully sorted. At each step the goal is to find the smallest element in the
  // range [i, end[ -- i.e. the i-th smallest element. The end - 1 element is
  // not visited by the outer loop as `swap` will eventually place the biggest
  // element there.
  for (auto i = begin, e = end - 1; i != e; ++i)
    std::swap(*std::min_element(i, end), *i);
}
}
