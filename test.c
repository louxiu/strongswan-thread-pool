#include <stdio.h>
#include "processing/processor.h"
#include "test.h"
#include "job_test.h"

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
