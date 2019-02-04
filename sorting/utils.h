
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
}
