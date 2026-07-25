#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

/* Tampon boyutu - Maskeleme optimizasyonu için mutlaka 2'nin kuvveti olmalıdır
 * (16 = 2^4) */
#define RING_BUFFER_SIZE 16U

/**
 * @brief Ring Buffer fonksiyonlarının geri dönüş durum kodları.
 */
typedef enum {
  RING_BUFFER_OK = 0,    /* İşlem başarılı */
  RING_BUFFER_EMPTY,     /* Tampon boş, okuma yapılamaz */
  RING_BUFFER_FULL,      /* Tampon dolu, yazma yapılamaz */
  RING_BUFFER_NULL_ERROR /* Geçersiz pointer (NULL) parametresi geçildi */
} RingBufferStatus_t;

/**
 * @brief Ring Buffer kontrol yapısı.
 */
typedef struct {
  uint8_t buffer[RING_BUFFER_SIZE]; /* Statik veri alanı */
  volatile uint16_t head;           /* Veri yazılacak indeks */
  volatile uint16_t tail;           /* Veri okunacak indeks */
  volatile uint16_t count;          /* Tampondaki veri adedi */
} RingBuffer_t;

/* Genel API Fonksiyon Bildirimleri */
RingBufferStatus_t RingBuffer_Init(RingBuffer_t *const me);
RingBufferStatus_t RingBuffer_Push(RingBuffer_t *const me, uint8_t data);
RingBufferStatus_t RingBuffer_Pop(RingBuffer_t *const me, uint8_t *const data);

/* Yardımcı (Helper) Durum Fonksiyonları */
bool RingBuffer_IsFull(const RingBuffer_t *const me);
bool RingBuffer_IsEmpty(const RingBuffer_t *const me);

#endif