
#include "gtest/gtest.h"

#include <random>

// Exercise 2.14
//
// Consider the problem of adding two n-bit binary integers, stored in two
// n-element arrays A and B. The sum of the two integers should be stored in
// binary form in ab (n + 1)-element array C. State the problem formally and
// write code for adding the two integers.

namespace cs {
template <size_t N>
std::bitset<N> make_random_integer() {
  std::mt19937 generator;
  std::bernoulli_distribution distribution;

  std::bitset<N> A;
  for (decltype(N) i = 0, e = N; i != e; ++i)
    A[i] = distribution(generator);
  return A;
}

template <size_t N>
unsigned long long as_integer(const std::bitset<N> &A) {
  auto AInt = 0ull;
  for (decltype(N) i = 0, e = N; i != e; ++i)
    AInt += A[i] << i;
  return AInt;
}

template <size_t N>
std::bitset<N + 1> add_integers(const std::bitset<N> &A,
                                const std::bitset<N> &B) {
  std::bitset<N + 1> C;

  auto Carry = 0;
  for (decltype(N) i = 0, e = N; i != e; ++i) {
    auto CurCarry = Carry;
    Carry = (CurCarry & (A[i] ^ B[i])) || (A[i] & B[i]);
    C[i] = A[i] ^ B[i] ^ CurCarry;
  }
  C[N] = Carry;

  return C;
}
}

using namespace cs;

TEST(Chapter2, Add2NBitBinaryIntegers) {
  auto A = make_random_integer<8>(), B = make_random_integer<8>();
  auto C = add_integers(A, B);
  EXPECT_EQ(as_integer(C), as_integer(A) + as_integer(B));
}
