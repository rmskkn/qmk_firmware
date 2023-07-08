#include <sys/stat.h>
#include <sys/types.h>

#pragma GCC diagnostic ignored "-Wmissing-prototypes"

__attribute__((weak, used)) int _open_r(struct _reent *r, const char *path, int flag, int m) {
    return -1;
}

__attribute__((weak, used)) int _lseek_r(struct _reent *r, int file, int ptr, int dir) {
    return -1;
}

__attribute__((weak, used)) int _read_r(struct _reent *r, int file, char *ptr, int len) {
    return -1;
}

__attribute__((weak, used)) int _write_r(struct _reent *r, int file, char *ptr, int len) {
    return -1;
}

__attribute__((weak, used)) int _close_r(struct _reent *r, int file) {
    return -1;
}

__attribute__((weak, used)) int _link_r(struct _reent *r, const char *oldpath, const char *newpath) {
    return -1;
}

__attribute__((weak, used)) int _unlink_r(struct _reent *r, const char *path) {
    return -1;
}

__attribute__((weak, used)) clock_t _times_r(struct _reent *r, void *t) {
    return -1;
}

__attribute__((weak, used)) int _fstat_r(struct _reent *r, int file, struct stat *st) {
    return -1;
}

__attribute__((weak, used)) int _isatty_r(struct _reent *r, int fd) {
    return 0;
}

__attribute__((weak, used)) caddr_t _sbrk_r(struct _reent *r, int incr) {
    return (caddr_t)-1;
}

__attribute__((weak, used)) int _kill_r(int pid, int sig) {
    return -1;
}

__attribute__((weak, used)) pid_t _getpid_r(void) {
    return 1;
}

__attribute__((weak, used)) void _fini(void) {
    return;
}

__attribute__((weak, used))  int pthread_setcancelstate(int state, int *oldstate) {
    (void)state;
    (void)oldstate;

    return 0;
}

__attribute__((weak, used)) struct _reent * __getreent(void)
{
    return NULL;
}

__attribute__((weak, used, noreturn)) void _exit(int i) {
    while (1)
        ;
}

#pragma GCC diagnostic pop
