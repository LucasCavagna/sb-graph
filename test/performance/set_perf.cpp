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

TEST(SetPerf, OrdIntersection)
{
  int N = 6000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersection)
{
  int N = 6000;

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
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionInters)
{
  int N = 6000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersectionInters)
{
  int N = 6000;

  SBG::LIB::UnordSet s1, s2;
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
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionUnivers)
{
  int N = 6000;

  SBG::LIB::OrdSet s1, s2;

  SBG::LIB::Interval i(0, 1, 1000000);
  s1.emplaceBack(i);
  

  for (int j = 0; j < N; j+=2) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersectionUnivers)
{
  int N = 6000;

  SBG::LIB::UnordSet s1, s2;

  SBG::LIB::Interval i(0, 1, 1000000);
  s1.emplaceBack(i);
  

  for (int j = 0; j < N; j+=2) {
    SBG::LIB::Interval i(j*105+1, 1, (j+1)*105);
    s2.emplaceBack(i);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}


TEST(SetPerf, OrdIntersectionThreeDims)
{
  int N = 6000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersectionThreeDims)
{
  int N = 6000;

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
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}


TEST(SetPerf, OrdIntersectionMultiInters)
{
  int N = 24000;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(0, 1, 1000000);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j+=1) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+10)*100);
    SBG::LIB::Interval i2(j*105+1, 1, (j+1)*105);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersectionMultiInters)
{
  int N = 24000;

  SBG::LIB::UnordSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(0, 1, 1000000);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j+=1) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+10)*100);
    SBG::LIB::Interval i2(j*105+1, 1, (j+1)*105);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionTotalInters)
{
  int N = 50;

  SBG::LIB::OrdSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(0, 1, 1000000);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j+=1) {
    SBG::LIB::Interval i2(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i1(0, 1, 1000000);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersectionTotalInters)
{
  int N = 0;

  SBG::LIB::UnordSet s1, s2;
  for (int j = 0; j < N; j++) {
    SBG::LIB::Interval i1(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i2(0, 1, 10000000);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s1.emplaceBack(mdi);
  }

  for (int j = 0; j < N; j+=1) {
    SBG::LIB::Interval i2(j*100+1, 1, (j+1)*100);
    SBG::LIB::Interval i1(0, 1, 10000000);
    SBG::LIB::MultiDimInter mdi;
    mdi.emplaceBack(i1);
    mdi.emplaceBack(i2);
    s2.emplaceBack(mdi);
  }

  auto start = std::chrono::high_resolution_clock::now();
  s1.intersection(s2);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionFiveDims)
{
  int N = 6000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordIntersectionFiveDims)
{
  int N = 6000;

  SBG::LIB::UnordSet s1, s2;
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
  std::cout << "UNORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdDifference)
{
  int N = 6000;

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
  std::cout << "ORDERED DIFFERENCE TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordDifference)
{
  int N = 6000;

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
  std::cout << "UNORDERED DIFFERENCE TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdUnion)
{
  int N = 6000;

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
  std::cout << "ORDERED UNION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, UnordUnion)
{
  int N = 6000;

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
  std::cout << "UNORDERED UNION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}


TEST(SetPerf, OrdIntersectionLinearVerification1)
{
  int N = 2000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionLinearVerification2)
{
  int N = 4000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}

TEST(SetPerf, OrdIntersectionLinearVerification3)
{
  int N = 6000;

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
  std::cout << "ORDERED INTERSECTION TEST elapsed time: " << elapsed.count() << "ms\n";

  SUCCEED();
}


