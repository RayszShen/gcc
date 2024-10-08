#ifndef HAVE_DEFINED_SAT_ARITH_DATA_H
#define HAVE_DEFINED_SAT_ARITH_DATA_H

#define TEST_UNARY_STRUCT_NAME(T1, T2) test_##T1##_##T2##_s
#define TEST_UNARY_STRUCT_DECL(T1, T2) struct TEST_UNARY_STRUCT_NAME(T1, T2)
#define TEST_UNARY_STRUCT(T1, T2)       \
  struct TEST_UNARY_STRUCT_NAME(T1, T2) \
    {                                   \
      T1 to;                            \
      T2 from;                          \
    };

#define TEST_BINARY_STRUCT_NAME(T, NAME) test_##T##_##NAME##_s
#define TEST_BINARY_STRUCT_DECL(T, NAME) struct TEST_BINARY_STRUCT_NAME(T, NAME)
#define TEST_BINARY_STRUCT(T, NAME)       \
  struct TEST_BINARY_STRUCT_NAME(T, NAME) \
    {                                     \
      T a, b;                             \
      T expect;                           \
    };

#define TEST_UNARY_DATA(T1, T2)      t_##T1##_##T2##_s
#define TEST_UNARY_DATA_WRAP(T1, T2) TEST_UNARY_DATA(T1, T2)

#define TEST_BINARY_DATA(T, NAME)      t_##T##_##NAME##_s
#define TEST_BINARY_DATA_WRAP(T, NAME) TEST_BINARY_DATA(T, NAME)

TEST_UNARY_STRUCT (uint8_t, uint16_t)
TEST_UNARY_STRUCT (uint8_t, uint32_t)
TEST_UNARY_STRUCT (uint8_t, uint64_t)
TEST_UNARY_STRUCT (uint16_t, uint32_t)
TEST_UNARY_STRUCT (uint16_t, uint64_t)
TEST_UNARY_STRUCT (uint32_t, uint64_t)

TEST_BINARY_STRUCT (int8_t,  ssadd)
TEST_BINARY_STRUCT (int16_t, ssadd)
TEST_BINARY_STRUCT (int32_t, ssadd)
TEST_BINARY_STRUCT (int64_t, ssadd)

TEST_BINARY_STRUCT (int8_t,  sssub)
TEST_BINARY_STRUCT (int16_t, sssub)
TEST_BINARY_STRUCT (int32_t, sssub)
TEST_BINARY_STRUCT (int64_t, sssub)

TEST_UNARY_STRUCT_DECL(uint8_t, uint16_t) \
  TEST_UNARY_DATA(uint8_t, uint16_t)[] =
{
  {  0,     0},
  {  2,     2},
  {254,   254},
  {255,   255},
  {255,   256},
  {255, 65534},
  {255, 65535},
};

TEST_UNARY_STRUCT_DECL(uint8_t, uint32_t) \
  TEST_UNARY_DATA(uint8_t, uint32_t)[] =
{
  {  0,          0},
  {  2,          2},
  {254,        254},
  {255,        255},
  {255,        256},
  {255,      65534},
  {255,      65535},
  {255,      65536},
  {255, 4294967294},
  {255, 4294967295},
};

TEST_UNARY_STRUCT_DECL(uint8_t, uint64_t) \
  TEST_UNARY_DATA(uint8_t, uint64_t)[] =
{
  {  0,                     0},
  {  2,                     2},
  {254,                   254},
  {255,                   255},
  {255,                   256},
  {255,                 65534},
  {255,                 65535},
  {255,                 65536},
  {255,            4294967294},
  {255,            4294967295},
  {255,            4294967296},
  {255, 18446744073709551614u},
  {255, 18446744073709551615u},
};

TEST_UNARY_STRUCT_DECL(uint16_t, uint32_t) \
  TEST_UNARY_DATA(uint16_t, uint32_t)[] =
{
  {    0,          0},
  {    5,          5},
  {65534,      65534},
  {65535,      65535},
  {65535,      65536},
  {65535, 4294967294},
  {65535, 4294967295},
};

TEST_UNARY_STRUCT_DECL(uint16_t, uint64_t) \
  TEST_UNARY_DATA(uint16_t, uint64_t)[] =
{
  {    0,                     0},
  {    5,                     5},
  {65534,                 65534},
  {65535,                 65535},
  {65535,                 65536},
  {65535,            4294967294},
  {65535,            4294967295},
  {65535,            4294967296},
  {65535, 18446744073709551614u},
  {65535, 18446744073709551615u},
};

TEST_UNARY_STRUCT_DECL(uint32_t, uint64_t) \
  TEST_UNARY_DATA(uint32_t, uint64_t)[] =
{
  {    0,                          0},
  {    9,                          9},
  {4294967294,            4294967294},
  {4294967295,            4294967295},
  {4294967295,            4294967296},
  {4294967295, 18446744073709551614u},
  {4294967295, 18446744073709551615u},
};

TEST_BINARY_STRUCT_DECL(int8_t, ssadd) TEST_BINARY_DATA(int8_t, ssadd)[] =
{
  {   0,    0,    0},
  {   2,    2,    4},
  { 126,    1,  127},
  { 127,    1,  127},
  { 127,  127,  127},
  {  -7,   -4,  -11},
  {-128,   -1, -128},
  {-127,   -1, -128},
  {-128, -128, -128},
  {-128,  127,   -1},
  {-127,  127,    0},
  {-122,  105,  -17},
  {-122,  125,    3},
};

TEST_BINARY_STRUCT_DECL(int16_t, ssadd) TEST_BINARY_DATA(int16_t, ssadd)[] =
{
  {     0,      0,      0},
  {     2,      2,      4},
  { 32766,      1,  32767},
  { 32767,      1,  32767},
  { 32767,  32767,  32767},
  {    -7,     -4,    -11},
  {-32768,     -1, -32768},
  {-32767,     -1, -32768},
  {-32768, -32768, -32768},
  {-32768,  32767,     -1},
  {-32767,  32767,      0},
  {-32732,  32712,    -20},
  {-32732,  32734,      2},
};

TEST_BINARY_STRUCT_DECL(int32_t, ssadd) TEST_BINARY_DATA(int32_t, ssadd)[] =
{
  {          0,           0,           0},
  {          2,           2,           4},
  { 2147483646,           1,  2147483647},
  { 2147483647,           1,  2147483647},
  { 2147483647,  2147483647,  2147483647},
  {         -7,          -4,         -11},
  {-2147483648,          -1, -2147483648},
  {-2147483647,          -1, -2147483648},
  {-2147483648, -2147483648, -2147483648},
  {-2147483648,  2147483647,          -1},
  {-2147483647,  2147483647,           0},
  {-2147483613,  2147483601,         -12},
  {-2147483613,  2147483637,          24},
};

TEST_BINARY_STRUCT_DECL(int64_t, ssadd) TEST_BINARY_DATA(int64_t, ssadd)[] =
{
  {                      0,                       0,                       0},
  {                      2,                       2,                       4},
  {  9223372036854775806ll,                       1,   9223372036854775807ll},
  {  9223372036854775807ll,                       1,   9223372036854775807ll},
  {  9223372036854775807ll,   9223372036854775807ll,   9223372036854775807ll},
  {                     -7,                      -4,                     -11},
  {-9223372036854775808ull,                      -1, -9223372036854775808ull},
  { -9223372036854775807ll,                      -1, -9223372036854775808ull},
  {-9223372036854775808ull, -9223372036854775808ull, -9223372036854775808ull},
  {-9223372036854775808ull,   9223372036854775807ll,                      -1},
  { -9223372036854775807ll,   9223372036854775807ll,                       0},
  { -9223372036854775803ll,   9223372036854775800ll,                      -3},
  { -9223372036854775803ll,   9223372036854775805ll,                       2},
};

TEST_BINARY_STRUCT_DECL(int8_t, sssub) TEST_BINARY_DATA(int8_t, sssub)[] =
{
  {   0,    0,    0},
  {   2,    4,   -2},
  { 126,   -1,  127},
  { 127,   -1,  127},
  { 127, -127,  127},
  {  -7,   -4,   -3},
  {-127,    1, -128},
  {-128,    1, -128},
  {-128,  127, -128},
  {-128, -127,   -1},
  {-124, -127,    3},
  {-125, -120,   -5},
  { 126,  120,    6},
};

TEST_BINARY_STRUCT_DECL(int16_t, sssub) TEST_BINARY_DATA(int16_t, sssub)[] =
{
  {     0,      0,      0},
  {     2,      4,     -2},
  { 32766,     -1,  32767},
  { 32767,     -1,  32767},
  { 32767, -32767,  32767},
  {    -7,     -4,     -3},
  {-32767,      1, -32768},
  {-32768,      1, -32768},
  {-32768,  32767, -32768},
  {-32768, -32767,     -1},
  {-32764, -32767,      3},
  {-32765, -32760,     -5},
  { 32766,  32760,      6},
};

TEST_BINARY_STRUCT_DECL(int32_t, sssub) TEST_BINARY_DATA(int32_t, sssub)[] =
{
  {          0,           0,           0},
  {          2,           4,          -2},
  { 2147483646,          -1,  2147483647},
  { 2147483647,          -1,  2147483647},
  { 2147483647, -2147483647,  2147483647},
  {         -7,          -4,          -3},
  {-2147483647,           1, -2147483648},
  {-2147483648,           1, -2147483648},
  {-2147483648,  2147483647, -2147483648},
  {-2147483648, -2147483647,          -1},
  {-2147483644, -2147483647,           3},
  {-2147483645, -2147483640,          -5},
  { 2147483646,  2147483640,           6},
};

TEST_BINARY_STRUCT_DECL(int64_t, sssub) TEST_BINARY_DATA(int64_t, sssub)[] =
{
  {                      0,                       0,                       0},
  {                      2,                       4,                      -2},
  {  9223372036854775806ll,                      -1,   9223372036854775807ll},
  {  9223372036854775807ll,                      -1,   9223372036854775807ll},
  {  9223372036854775807ll,  -9223372036854775807ll,   9223372036854775807ll},
  {                     -7,                      -4,                      -3},
  { -9223372036854775807ll,                       1, -9223372036854775808ull},
  {-9223372036854775808ull,                       1, -9223372036854775808ull},
  {-9223372036854775808ull,   9223372036854775807ll, -9223372036854775808ull},
  {-9223372036854775808ull,  -9223372036854775807ll,                      -1},
  { -9223372036854775804ll,  -9223372036854775807ll,                       3},
  { -9223372036854775805ll,  -9223372036854775800ll,                      -5},
  {  9223372036854775806ll,   9223372036854775800ll,                       6},
};

#endif
