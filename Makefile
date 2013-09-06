all : thread_pool

thread_pool: test.c
	gcc -g test.c job_test.c -I. -I./processing -I./threading processing/processor.c threading/*.c utils.c utils/linked_list.c -lpthread -o test