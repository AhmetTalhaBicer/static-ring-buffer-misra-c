#ifndef UNITY_FRAMEWORK_H
#define UNITY_FRAMEWORK_H

#include <stdio.h>

void UnityBegin(const char* filename);
int UnityEnd(void);
void UnityAssert(int condition, const char* message, const char* file, int line);

#define TEST_PROTECT() 1
#define TEST_ABORT() return

#define RUN_TEST(TestFunc) \
    printf("Running %s...", #TestFunc); \
    TestFunc(); \
    printf(" [PASSED]\n");

#define TEST_ASSERT(condition) \
    UnityAssert((condition), #condition, __FILE__, __LINE__)

#define TEST_ASSERT_EQUAL_INT(expected, actual) \
    UnityAssert((expected) == (actual), "VAL_NOT_EQUAL", __FILE__, __LINE__)

#endif /* UNITY_FRAMEWORK_H */