#define TIMEVAL_TO_TIMESPEC(tv, ts) {                                   \
        (ts)->tv_sec = (tv)->tv_sec;                                    \
        (ts)->tv_nsec = (tv)->tv_usec * 1000;                           \
}
#define TIMESPEC_TO_TIMEVAL(tv, ts) {                                   \
        (tv)->tv_sec = (ts)->tv_sec;                                    \
        (tv)->tv_usec = (ts)->tv_nsec / 1000;                           \
}
#define timespeccmp(tsp, usp, cmp)                                      \
        (((tsp)->tv_sec == (usp)->tv_sec) ?                             \
            ((tsp)->tv_nsec cmp (usp)->tv_nsec) :                       \
             ((tsp)->tv_sec cmp (usp)->tv_sec))
#define timersub(s,t,a) ( (a)->tv_sec = (s)->tv_sec - (t)->tv_sec,      \
        ((a)->tv_usec = (s)->tv_usec - (t)->tv_usec) < 0 &&             \
        ((a)->tv_usec += 1000000, (a)->tv_sec--) )

#include_next <sys/time.h>
#include_next <time.h>
