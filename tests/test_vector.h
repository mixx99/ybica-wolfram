#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#include "vector.h"

#define TEST_NUMBER 100

void test_vector(){
  test_sum();
}

void test_sum(){
  int result = 0;
  for(int i = 0; i < TEST_NUMBER; ++i){
    vector v1 = {rand(), rand(), rand()};
    vector v2 = {rand(), rand(), rand()};
    if(INT_MAX - v2.x > v1.x)
      continue;
    if(INT_MAX - v2.y > v1.y)
      continue;
    if(INT_MAX - v2.z > v1.z)
      continue;
    vector expected = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
    vector result = sum(&v1, &v2);
    assert(expected.x == result.x && expected.y == result.y && expected.z == result.z);
  }
  printf("TEST_SUM success!\n");
}

#endif