#include <stdio.h>
#include "ring_buffer.h"

int main(void) {
    RingBuffer_t rx_buffer;
    RingBufferStatus_t status;
    uint8_t read_data = 0U;

    printf("--- RING BUFFER TEST BASLADI ---\n\n");

    /* 1. Tamponu İlklendir */
    status = RingBuffer_Init(&rx_buffer);
    if (status == RING_BUFFER_OK) {
        printf("[OK] Tampon basariyla ilklendirildi.\n");
    }

    /* 2. Veri Ekle (Push) */
    printf("\nVeriler ekleniyor...\n");
    RingBuffer_Push(&rx_buffer, 0xAA);
    printf("0xAA eklendi. Anlik Veri Sayisi: %d\n", rx_buffer.count);
    
    RingBuffer_Push(&rx_buffer, 0xBB);
    printf("0xBB eklendi. Anlik Veri Sayisi: %d\n", rx_buffer.count);

    /* 3. Veri Oku (Pop) */
    printf("\nVeriler okunuyor...\n");
    while (RingBuffer_IsEmpty(&rx_buffer) == false) {
        status = RingBuffer_Pop(&rx_buffer, &read_data);
        if (status == RING_BUFFER_OK) {
            printf("[OK] Okunan Veri: 0x%02X\n", read_data);
        }
    }

    /* 4. Boş Tampondan Okuma Denemesi (Underflow Test) */
    status = RingBuffer_Pop(&rx_buffer, &read_data);
    if (status == RING_BUFFER_EMPTY) {
        printf("\n[PASSED] Bos tampon korumasi calisiyor (RING_BUFFER_EMPTY).\n");
    }

    printf("\n--- TEST BITTI ---\n");
    return 0;
}