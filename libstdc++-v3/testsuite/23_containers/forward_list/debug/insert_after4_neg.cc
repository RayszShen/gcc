// Copyright (C) 2013-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.
//
// { dg-do run { target c++11 xfail *-*-* } }
// { dg-require-debug-mode "" }
// { dg-options "-D_GLIBCXX_DEBUG_PEDANTIC" }

#include <forward_list>
#include <iterator>

void test01()
{
  std::forward_list<int> fl{ 1, 2, 3 };
  fl.insert_after(fl.before_begin(), fl.begin(), std::next(fl.begin(), 2));
}

int main()
{
  test01();
  return 0;
}
