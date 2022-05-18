#include <stdio.h>
#include <inttypes.h>
#include <sys/queue.h>

#include "lsquic.h"
#include "lsquic_int_types.h"
#include "lsquic_hash.h"

#include "lsquic_conn.h"

#define LSQUIC_LOGGER_MODULE LSQLM_MULTICONN
#include "lsquic_logger.h"


void lsquic_test_hello_word(){
    LSQ_INFO("Hello, world\n");
    return;
}


void
lsquic_conn_make_stream (lsquic_conn_t *conn){
    //LSQ_INFO("lsquic_conn_make_stream before\n");
    //LSQ_INFO("conn->mcn_n_conns: %d", conn->mcn_n_conns);
    lsquic_conn_make_stream_single(conn->main_conn);
    //LSQ_INFO("lsquic_conn_make_stream after\n");
    return;
}

lsquic_conn_ctx_t *
lsquic_conn_get_ctx (const lsquic_conn_t *conn){
    LSQ_INFO("In lsquic_conn_get_ctx\n");
    return lsquic_conn_get_ctx_single(conn->main_conn);
}

void
lsquic_conn_close (lsquic_conn_t *conn){
    LSQ_INFO("In lsquic_conn_close\n");
    lsquic_conn_close_single(conn->main_conn);
    conn->mcn_n_conns -= 1;
    //if conn->mcn_n_conns <= 0{
//      "close"(conn);
//    }
    return;
}

void
lsquic_conn_set_ctx (lsquic_conn_t *conn, lsquic_conn_ctx_t *conn_ctx){
    conn->mcn_conn_ctx = conn_ctx;
    lsquic_conn_set_ctx_single(conn->main_conn, (lsquic_conn_single_ctx_t *) conn_ctx);
    return;
}

const char *
lsquic_conn_crypto_cipher (const lsquic_conn_t *c){
    LSQ_INFO("In lsquic_conn_crypto_cipher");
    return lsquic_conn_crypto_cipher_single(c->main_conn);
}

enum lsquic_version
lsquic_conn_quic_version (const lsquic_conn_t *c){
    return lsquic_conn_quic_version_single(c->main_conn);
}

int
lsquic_conn_crypto_keysize (const lsquic_conn_t *c){
    return lsquic_conn_crypto_keysize_single(c->main_conn);
}

int
lsquic_conn_crypto_alg_keysize (const lsquic_conn_t *c){
    return lsquic_conn_crypto_alg_keysize_single(c->main_conn);
}

struct lsquic_conn_single
lsquic_conn_open_subflow(lsquic_conn_t *c){
    // opening
    // setting
    // dealing with conn_id
}


void
lsquic_conn_call_on_new_subconn(const lsquic_conn_t *lconn){
    //conn->cn_if->ci_client_call_on_new(conn->cn_main_conn);
    struct lsquic_conn *tmp_conn = lconn;
    struct lsquic_conn_single *tmp_single;
    
    // change sub_conn and conn
    tmp_single = lconn->main_conn;
    tmp_conn->main_conn = lconn->sub_conn;
    tmp_conn->sub_conn = tmp_single;

    lsquic_conn_make_stream(tmp_conn);

    tmp_conn->sub_conn = tmp_conn->main_conn;
    tmp_conn->main_conn = tmp_single;

    return;
}