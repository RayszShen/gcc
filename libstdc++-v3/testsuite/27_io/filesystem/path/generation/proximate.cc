// Copyright (C) 2017-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// { dg-do run { target c++17 } }

#include <filesystem>
#include <testsuite_hooks.h>
#include <testsuite_fs.h>

using std::filesystem::path;
using __gnu_test::compare_paths;

// Normalize directory-separators
std::string operator""_norm(const char* s, std::size_t n)
{
  std::string str(s, n);
#if defined(__MINGW32__) || defined(__MINGW64__)
  for (auto& c : str)
    if (c == '/')
      c = '\\';
#endif
  return str;
}

void
test01()
{
  // C++17 [fs.path.gen] p5
  compare_paths( path("/a/d").lexically_proximate("/a/b/c"), "../../d"_norm );
  compare_paths( path("/a/b/c").lexically_proximate("/a/d"), "../b/c"_norm );
  compare_paths( path("a/b/c").lexically_proximate("a"), "b/c"_norm );
  compare_paths( path("a/b/c").lexically_proximate("a/b/c/x/y"), "../.."_norm );
  compare_paths( path("a/b/c").lexically_proximate("a/b/c"), "."_norm );
  compare_paths( path("a/b").lexically_proximate("c/d"), "../../a/b"_norm );
}

void
test02()
{
  path p = "a/b/c";
  compare_paths( p.lexically_proximate(p), "." );
  compare_paths( p.lexically_proximate("a/../a/b/../b/c/../c/."),
		 "../../b/c"_norm );
  compare_paths( p.lexically_proximate("../../../"), p );
}

int
main()
{
  test01();
  test02();
}
