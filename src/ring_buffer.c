#include "../include/ring_buffer.h"
#include <stdbool.h>
#include <stddef.h> /* NULL tanımı için gereklidir */
#include <stdint.h>

bool RingBuffer_IsEmpty(const RingBuffer_t *const me) {
  if (me == NULL) {
    return true;
  }
  return (me->count == 0U);
}

bool RingBuffer_IsFull(const RingBuffer_t *const me) {
  if (me == NULL) {
    return false;
  }
  return (me->count == RING_BUFFER_SIZE);
}

RingBufferStatus_t RingBuffer_Init(RingBuffer_t *const me) {
  if (me == NULL) {
    return RING_BUFFER_NULL_ERROR;
  }

  me->head = 0U;
  me->tail = 0U;
  me->count = 0U;

  for (uint16_t i = 0U; i < RING_BUFFER_SIZE; i++) {
    me->buffer[i] = 0U;
  }

  return RING_BUFFER_OK;
}
