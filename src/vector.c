#include "vector.h"

#include <math.h>
#include <stdio.h>

static inline double get_length(const vector *v);

static inline double get_length(const vector *v) {
  if (v == NULL)
    return 0;
  return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

void print_vector(const vector *v) {
  if(v == NULL)
    printf("NULL-vector\n");
  printf("%.2lf %.2lf %.2lf\n", v->x, v->y, v->z);
}

vector sum(const vector *v1, const vector *v2) {
  vector result = {0};
  if (v1 == NULL && v2 == NULL)
    return result;
  if (v1 == NULL && v2 != NULL)
    return *v2;
  if (v1 != NULL && v2 == NULL)
    return *v1;
  result.x = v1->x + v2->x;
  result.y = v1->y + v2->y;
  result.z = v1->z + v2->z;
  return result;
}

vector sub(const vector *v1, const vector *v2) {
  vector result = {0};
  if (v1 == NULL && v2 == NULL)
    return result;
  if (v1 == NULL && v2 != NULL) {
    result.x = -(v2->x);
    result.y = -(v2->y);
    result.z = -(v2->z);
    return result;
  }
  if (v1 != NULL && v2 == NULL)
    return *v1;
  result.x = v1->x - v2->x;
  result.y = v1->y - v2->y;
  result.z = v1->z - v2->z;
  return result;
}

double dot(const vector *v1, const vector *v2, double theta) {
  if (v1 == NULL || v2 == NULL)
    return 0;
  return get_length(v1) * get_length(v2) * cos(theta);
}

vector cross(const vector *v1, const vector *v2) {
  vector result = {0};
  if (v1 == NULL || v2 == NULL)
    return result;
  result.x = v1->y * v2->z - v1->z * v2->y;
  result.y = v1->z * v2->x - v1->x * v2->z;
  result.z = v1->x * v2->y - v1->y * v2->x;
  return result;
}
