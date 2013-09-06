This nice thread pool is stripped from strongswan 4.5.0.

1. job is the most commcon type of job
2. callback job is a special job that can be executed more than one time and contain select and other call.
3. scheduled jobs, these jobs are timer jobs and scheduled by a scheduler

The cancel of job is well supported.
There are child jobs
The scheduler is a callback job


Other:
1. Implementation of the rwlock_t interface uses mutex_t and condvar_t primitives
2. leak detect module
3. simple lex parser interface
