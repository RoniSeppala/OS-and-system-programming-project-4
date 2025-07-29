#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]){
    int before = getreadcount();
    char buf[1];
    read(0, buf, 1);
    int after = getreadcount();
    // fd 1 is stdout
    printf(1, "readcount before: %d, after: %d\n", before, after);
    exit();
}