# Implementation of a Memory-Safe Vector

## Background

One of the major sources of potential memory errors in C++ is that standard library vectors can easily be accessed out-of-bounds, without necessarily generating any error messages.
To be more specific, although the vector `at` method includes out-of-bounds checking (and throws an exception in the event of an out-of-bounds access attempt), the vector subscript operator (`[]`) does **not** including out-of-bounds checking.
This means that any use of the vector subscript operator - which is used far more often by most programmers than the `at` method - is potentially unsafe.

In this problem, you will create a custom vector class that performs an out-of-bounds check for the subscript operator, and throws an exception when an attempt is made to access the vector out-of-bounds.
There are a few ways you could *imagine* creating a class of this sort:

1. By creating an entirely new implementation of vector functionality that does not reuse any code from `std::vector`.
2. By inheriting from the `std::vector` class.
3. By using "composition," which involves creating a new class that does **not** inherit from `std::vector`, but that includes an `std::vector` as a class **member**.

Option (1) is not good solution, as it would require essentially completely recreating the code for an `std::vector`, with minor modifications.
Option (2) might *seem* like the obvious choice, but it really isn't.
Inheriting from standard library classes in generally discouraged for a variety of reasons - including the fact that this tends to break encapsulation, and that classes like `std::vector` lack a virtual destructor.
You can read more about the problems with inheriting from `std::vector` in [this GeeksforGeeks article](https://www.geeksforgeeks.org/why-should-we-not-inherit-std-vector-in-cpp/) and in [this Stack Overflow discussion](https://stackoverflow.com/questions/4353203/thou-shalt-not-inherit-from-stdvector).

For the purpose of this problem, you are **required** to use approach (3) - that is, to use composition.
This means that you will create a new template class (that does **not** inherit from `std::vector`), but that includes an `std::vector` as one of its class members.
You will then need to implement various class methods that reproduce the normal `std::vector` interface.
For example, if your class includes an `std::vector` called `myvec` as a member, it might also implement support for the vector `empty` method with the following class method:

```
  bool empty() const {
    return myvec.empty();
  }
```

Essentially, the new class is largely a wrapper around an `std::vector`, with methods that reproduce the normal interface for an `std::vector`.
The obvious downside to using composition is that you must reproduce the interface for all the methods of the `std::vector` class that you need.

## Task

Inside this repository, you will find an `src/main.cpp` file that performs some tests using three separate instances of `std::vector`, named `int_vec`, `double_vec`, and `list_vec`.
Change `int_vec`, `double_vec`, and `list_vec` from being instances of `std::vector` to being instances of a new template class called `SafeVector`.
`SafeVector` must use composition to support all the functionality of `std::vector` that is required by the tests in `src/main.cpp`, while also implementing out-of-bounds checking for the subscript operator.
It must throw an appropriate exception when an out-of-bounds access is attempted through the subscript operator.
Your `SafeVector` class must properly handle `const` vectors, and your `SafeVector::push_back` method must properly support move semantics.
Finally, ensure that your `SafeVector` class properly handles the situation in which the `.back()` method is called on an empty vector.

The only change you are permitted to make within the `main` function is to change the `std::vector` types to `SafeVector` types.
In other words, you should modify the declaration of the vectors to:

```
  SafeVector<int> int_vec;
  const SafeVector<double> double_vec = {1.1, 2.2, 3.3, 4.4};
  SafeVector<std::list<int>> list_vec;
```

In particular, do not change any of the code beyond the comment that says `DO NOT EDIT ANYTHING PAST THIS POINT!`.

## Hints

Solving this problem doesn't require writing a large amount of code (50 lines is more than enough), but it *does* require good attention to detail.
You'll need to understand and think carefully about how the `std::vector` class interface works (see [here](https://en.cppreference.com/w/cpp/container/vector) for the specification).
Pay attention to when you need to use references, and think about how you need to handle move semantics and constant vectors.
