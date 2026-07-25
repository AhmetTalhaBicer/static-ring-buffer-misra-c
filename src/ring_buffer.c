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

RingBufferStatus_t RingBuffer_Push(RingBuffer_t *const me, uint8_t data) {
  if (me == NULL) {
    return RING_BUFFER_NULL_ERROR;
  }
  if (RingBuffer_IsFull(me)) {
    return RING_BUFFER_FULL;
  }

  me->buffer[me->head] = data;
  me->head = (me->head + 1U) & (RING_BUFFER_SIZE - 1U);
  me->count++;

  return RING_BUFFER_OK;
}

RingBufferStatus_t RingBuffer_Pop(RingBuffer_t *const me, uint8_t *const data) {
  if ((me == NULL) || (data == NULL)) {
    return RING_BUFFER_NULL_ERROR;
  }
  if (RingBuffer_IsEmpty(me)) {
    return RING_BUFFER_EMPTY;
  }
  *data = me->buffer[me->tail];
  me->tail = (me->tail + 1U) & (RING_BUFFER_SIZE - 1U);
  me->count--;

  return RING_BUFFER_OK;
}