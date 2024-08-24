#include "information.h"

const char date[] __attribute__((at(BUILD_DATE)))       = __DATE__;
const char time[] __attribute__((at(BUILD_TIME)))       = __TIME__;
const char version[] __attribute__((at(BUILD_VERSION))) = "V1.0.0";
