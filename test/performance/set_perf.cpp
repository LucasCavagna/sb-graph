/*****************************************************************************

 This file is part of Set--Based Graph Library.

 SBG Library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 SBG Library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with SBG Library.  If not, see <http://www.gnu.org/licenses/>.

 ******************************************************************************/

#include <chrono>
#include <gtest/gtest.h>

#include "sbg/ord_pw_mdinter.hpp"
#include "sbg/unord_pw_mdinter.hpp"

TEST(SetPerf, Intersection)
{
  int N = 3;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, Difference)
{
  int N = 3;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.difference(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "DIFFERENCE TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, Union)
{
  int N = 3;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*95+1, 1, (j+1)*95);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.cup(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "UNION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersection)
{
  int N = 3;

  SBG::LIB::UnordSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordDifference)
{
  int N = 3;

  SBG::LIB::UnordSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.difference(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "DIFFERENCE TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordUnion)
{
  int N = 3;

  SBG::LIB::UnordSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*95+1, 1, (j+1)*95);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.cup(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "UNION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersection)
{
  int N = 3000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}
TEST(SetPerf, OrdIntersectionHalf)
{
  int N = 3000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j+=2) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionNxN)
{
  int N = 3000;

  SBG::LIB::OrdSet s1, s2;

  SBG::LIB::Interval i(0, 1, 100000);
  s1.emplaceBack(i);
  

  for (int j = 0; j < N; j+=2) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionMd)
{
  int N = 12000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i3(j*100+1, 1, (j+1)*100);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i2(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i3(j*105+1, 1, (j+1)*105);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnOrdIntersectionMd)
{
  int N = 12000;

  SBG::LIB::UnordSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i3(j*100+1, 1, (j+1)*100);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i2(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i3(j*105+1, 1, (j+1)*105);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION UNORD TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}



TEST(SetPerf, OrdIntersectionMd2)
{
  int N = 3000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i3(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i4(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i5(j*100+1, 1, (j+1)*100);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    mdi.emplaceBack(i4);
    mdi.emplaceBack(i5);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i2(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i3(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i4(j*105+1, 1, (j+1)*105);
    SBG::LIB::Interval i5(j*105+1, 1, (j+1)*105);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    mdi.emplaceBack(i4);
    mdi.emplaceBack(i5);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionMd3)
{
  int N = 3000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i3(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i4(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i5(j*100+1, 1, (j+1)*100);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    mdi.emplaceBack(i4);
    mdi.emplaceBack(i5);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N*3; j+=4) {
    SBG::LIB::Interval i1(j*205+1, 1, (j+1)*205);
    SBG::LIB::Interval i2(j*205+1, 1, (j+1)*205);
    SBG::LIB::Interval i3(j*205+1, 1, (j+1)*205);
    SBG::LIB::Interval i4(j*205+1, 1, (j+1)*205);
    SBG::LIB::Interval i5(j*205+1, 1, (j+1)*205);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    mdi.emplaceBack(i3);
    mdi.emplaceBack(i4);
    mdi.emplaceBack(i5);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s2.intersection(s1);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdDifference)
{
  int N = 1000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.difference(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "DIFFERENCE TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdUnion)
{
  int N = 3;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*100+1, 1, (j+1)*100);
    s1.emplaceBack(i);
  }

  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i(j*95+1, 1, (j+1)*95);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.cup(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "UNION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}
