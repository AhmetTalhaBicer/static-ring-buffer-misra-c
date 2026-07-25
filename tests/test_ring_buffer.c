#include "unity.h"
#include "../include/ring_buffer.h"
#include <stddef.h>

static RingBuffer_t ring_buf;

/* Her testten önce çağrılan hazırlık fonksiyonu */
static void setUp(void) {
    (void)RingBuffer_Init(&ring_buf);
}

/* TEST 1: Başlatma Kontrolü */
static void test_Initialization_Should_Reset_Buffer(void) {
    TEST_ASSERT_EQUAL_INT(0U, ring_buf.count);
    TEST_ASSERT_EQUAL_INT(0U, ring_buf.head);
    TEST_ASSERT_EQUAL_INT(0U, ring_buf.tail);
    TEST_ASSERT(RingBuffer_IsEmpty(&ring_buf) == true);
}

/* TEST 2: REQ-NULL-DEFENSE (Geçersiz Pointer Koruması) */
static void test_Null_Pointer_Defense(void) {
    uint8_t data = 0U;
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_NULL_ERROR, RingBuffer_Init(NULL));
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_NULL_ERROR, RingBuffer_Push(NULL, 0xAA));
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_NULL_ERROR, RingBuffer_Pop(NULL, &data));
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_NULL_ERROR, RingBuffer_Pop(&ring_buf, NULL));
}

/* TEST 3: REQ-OVERFLOW-PROT (Taşma Koruması) */
static void test_Overflow_Protection(void) {
    /* Tampon kapasitesi kadar veri ekle (16 eleman) */
    for (uint16_t i = 0U; i < RING_BUFFER_SIZE; i++) {
        TEST_ASSERT_EQUAL_INT(RING_BUFFER_OK, RingBuffer_Push(&ring_buf, (uint8_t)i));
    }

    TEST_ASSERT(RingBuffer_IsFull(&ring_buf) == true);

    /* 17. Veriyi eklemeyi dene -> Taşma hatası dönmeli */
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_FULL, RingBuffer_Push(&ring_buf, 0xFF));
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_SIZE, ring_buf.count); /* Veri sayısı bozulmamalı */
}

/* TEST 4: REQ-UNDERFLOW-PROT (Boşaltma Koruması) */
void test_Underflow_Protection(void) {
    uint8_t data = 0xAA;
    
    TEST_ASSERT(RingBuffer_IsEmpty(&ring_buf) == true);
    /* Boş tampondan okuma dene */
    TEST_ASSERT_EQUAL_INT(RING_BUFFER_EMPTY, RingBuffer_Pop(&ring_buf, &data));
    TEST_ASSERT_EQUAL_INT(0xAA, data); /* Hedef veri değişkeni mutasyona uğramamalı */
}

/* TEST 5: Wrap-Around (Dairesel İndeksleme Mantığı) */
static void test_Buffer_Wrap_Around(void) {
    uint8_t data = 0U;

    /* Sınırı aşacak şekilde defalarca push-pop yap */
    for (uint16_t i = 0U; i < (RING_BUFFER_SIZE * 2U); i++) {
        TEST_ASSERT_EQUAL_INT(RING_BUFFER_OK, RingBuffer_Push(&ring_buf, (uint8_t)i));
        TEST_ASSERT_EQUAL_INT(RING_BUFFER_OK, RingBuffer_Pop(&ring_buf, &data));
        TEST_ASSERT_EQUAL_INT((uint8_t)i, data);
    }

    TEST_ASSERT(RingBuffer_IsEmpty(&ring_buf) == true);
}

int main(void) {
    UnityBegin(__FILE__);

    setUp();
    RUN_TEST(test_Initialization_Should_Reset_Buffer);
    
    setUp();
    RUN_TEST(test_Null_Pointer_Defense);

    setUp();
    RUN_TEST(test_Overflow_Protection);

    setUp();
    RUN_TEST(test_Underflow_Protection);

    setUp();
    RUN_TEST(test_Buffer_Wrap_Around);

    return UnityEnd();
}