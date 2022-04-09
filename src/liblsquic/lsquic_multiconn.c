#include "lsquic_multiconn.h"
#include <stdio.h>

#include <inttypes.h>
#include "lsquic_types.h"

#define LSQUIC_LOGGER_MODULE LSQLM_MULTICONN
#include "lsquic_logger.h"


void lsquic_test_hello_word(){
    LSQ_INFO("Hello, world\n");
    return;
}