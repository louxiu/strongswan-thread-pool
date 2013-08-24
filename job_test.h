typedef struct job_test_t job_test_t;

/* #include <library.h> */
/* #include <encoding/message.h> */
#include <processing/jobs/job.h>
#include "processing/processor.h"

extern processor_t *processor;

/**
 * Class representing an PROCESS_MESSAGE job.
 */
struct job_test_t {
	/**
	 * implements job_t interface
	 */
	job_t job_interface;
};

/**
 * Creates a job of type PROCESS_MESSAGE.
 *
 * @param message		message to process
 * @return				created process_message_job_t object
 */
job_test_t *job_test_create(char message, int peroid);
