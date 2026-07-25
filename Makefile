CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Iinclude

# Kaynak Dosyaları
SRCS = src/ring_buffer.c
TEST_SRCS = tests/test_ring_buffer.c tests/unity.c

# Hedefler
APP_TARGET = app.exe
TEST_TARGET = test_runner.exe

all: $(APP_TARGET)

$(APP_TARGET): main.c $(SRCS)
	$(CC) $(CFLAGS) -o $(APP_TARGET) main.c $(SRCS)

test: $(TEST_SRCS) $(SRCS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRCS) $(SRCS)
	./$(TEST_TARGET)

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction --suppress=staticFunction --error-exitcode=1 -I include src/

clean:
	rm -f *.o src/*.o tests/*.o $(APP_TARGET) $(TEST_TARGET)