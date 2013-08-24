#include <stdio.h>
#include "processing/processor.h"
#include "test.h"
#include "job_test.h"

/* gcc -g test.c processing/processor.c -I./processing  threading/\*.c utils.c -I. -I./threading -lpthread utils/linked_list.c */

/* 1. job is the most commcon type of job */
/* 2. callback job is a special job that can be executed more than one time and contain select and other call. */
/* 3. scheduled jobs, these jobs are timer jobs and scheduled by a scheduler */

/* The cancel of job is well supported */
/* There are child jobs? */
/* The scheduler is a callback job */

processor_t *processor;

/* argc >= 1 include argv[0] */
int main(int argc, char *argv[])
{
    /* Initalize the main thread */
    threads_init();
    
    processor = processor_create();
    processor->set_threads(processor, 2);
    
    job_test_create('a', 5);
    job_test_create('b', 1);
    
    sleep(20);
    processor->destroy(processor);
    threads_deinit();
    
    return 0;
}
