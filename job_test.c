#include <stdio.h>
#include <malloc.h>
#include "utils.h"
#include "job_test.h"

typedef struct job_test job_test;

struct job_test {
	/**
	 * implements job_t interface
	 */
	job_test_t public;
    char  message;
    int   peroid;
};

static void destroy(job_test *this)
{
    free(this);
    return;
}

static void execute(job_test *this)
{
    printf("message = %c\n", this->message);
    sleep(this->peroid);
    printf("message = %c\n", this->message);
    destroy(this);
    
    return;
}

job_test_t *job_test_create(char message, int peroid)
{
    job_test *this = malloc_thing(job_test);

	/* interface functions */
	this->public.job_interface.execute = (void (*) (job_t *)) execute;
	this->public.job_interface.destroy = (void(*)(job_t*))destroy;

	/* private variables */
	this->message = message;
    this->peroid = peroid;

    processor->queue_job(processor, (job_t*)&(this->public));
    
	return &(this->public);
}

