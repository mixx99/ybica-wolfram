#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdint.h>

typedef struct {
  double x, y, z;
} vector;

void print_vector(const vector *v);
vector sum(const vector *v1, const vector *v2);
vector sub(const vector *v1, const vector *v2);
double dot(const vector *v1, const vector *v2, double theta);
vector cross(const vector *v1, const vector *v2);

#endif // VECTOR_H_
