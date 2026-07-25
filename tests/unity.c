#include "unity.h"

static int test_failures = 0;

void UnityBegin(const char* filename) {
    (void)filename;
    test_failures = 0;
    printf("\n=== UNIT TEST SUITE STARTED ===\n\n");
}

int UnityEnd(void) {
    printf("\n=== TEST SUMMARY: %s ===\n", (test_failures == 0) ? "ALL PASSED" : "FAILED");
    return test_failures;
}

void UnityAssert(int condition, const char* message, const char* file, int line) {
    if (!condition) {
        printf("\n  [FAIL] %s:%d: %s\n", file, line, message);
        test_failures++;
    }
}