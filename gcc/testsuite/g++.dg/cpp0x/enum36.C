// PR c++/82307
// { dg-do run { target c++11 } }
// { dg-skip-if "requires hosted libstdc++ for cassert" { ! hostedlib } }

#include <cassert>

enum : short { VAL };

bool foo (int) { return true; }
bool foo (unsigned long long) { return false; }

int main()
{
  assert (foo (VAL));
}
