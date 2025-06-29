#pragma once
#include <stdint.h>

union DvarValue
{
  int8_t enabled;
  int32_t integer;
  int32_t value;
  int32_t vector;
  char string[4];
  int32_t color;
};

union DvarLimits
{
  struct
  {

    char stringCount[4];
    char strings[4];
  } enumeration;

  struct
  {

    int32_t min;
    int32_t max;
  } integer;

  struct
  {
    int32_t min;
    int32_t max;
  } value;

  struct
  {
    int32_t min;
    int32_t max;
  } vector;
};

struct dvar_s
{
  char name[4];
  int16_t flags;
  int8_t type;
  int8_t modified;
  DvarValue current;
  int32_t latched;
  int32_t reset;
  DvarLimits domain;
  int32_t next;
  int32_t hashNext;
};
typedef struct dvar_s dvar_t;