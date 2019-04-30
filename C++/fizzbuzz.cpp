// Helper macros to make compiler output a bit more readable, but keep the
// source readable too.
#define List _
#define Integer __

template <int Condition, typename A, typename B>
struct If;

template <typename A, typename B>
struct If<true, A, B> {
  typedef A result;
};

template <typename A, typename B>
struct If<false, A, B> {
  typedef B result;
};

struct Nil {};
struct Fizz {};
struct Buzz {};
struct FizzBuzz {};
template <int N>
struct Integer {
  static const int value = N;
};

template <typename Head, typename Rest>
struct List {
  typedef Head head;
  typedef Rest rest;
};

template <typename Container, typename Value>
struct PushFront {
  typedef List<Value, Container> result;
};

template <int N>
struct IntToFizzBuzz {
  typedef typename If<
      N % 15 == 0, FizzBuzz,
      typename If<N % 3 == 0, Fizz, typename If<N % 5 == 0, Buzz, Integer<N>>::
                                        result>::result>::result result;
};

template <int N>
struct DoFizzBuzz {
  typedef typename PushFront<typename IntToFizzBuzz<N>::result,
                             typename DoFizzBuzz<N - 1>::result>::result result;
};

template <>
struct DoFizzBuzz<0> {
  typedef Nil result;
};

template <typename T>
struct Print;

struct Print;

Print<DoFizzBuzz<100>::result> ___;
