/*
 * lsquic_conn.h -- Multiconnection
 */
#include "lsquic_conn_single.h"
#include<time.h>
#include<sys/time.h>

#ifndef LSQUIC_MULTICONN_H
#define LSQUIC_MULTICONN_H

struct lsquic_conn {
    struct lsquic_conn_single   *main_conn;
    lsquic_conn_ctx_t           *mcn_conn_ctx;
    int                         mcn_n_conns;
    struct lsquic_conn_single   *sub_conn;

    struct timeval              start;
    char                        is_switch;
    char                        switched;
    //lsquic_cid_t                main_dcid;
};

void 
lsquic_test_hello_word();

void
lsquic_conn_make_stream (lsquic_conn_t *); 

lsquic_conn_ctx_t *
lsquic_conn_get_ctx (const lsquic_conn_t *);

void
lsquic_conn_set_ctx (lsquic_conn_t *conn, lsquic_conn_ctx_t *conn_ctx);

void
lsquic_conn_close (lsquic_conn_t *);

const char *
lsquic_conn_crypto_cipher (const lsquic_conn_t *c);

enum lsquic_version
lsquic_conn_quic_version (const lsquic_conn_t *c);

int
lsquic_conn_crypto_keysize (const lsquic_conn_t *c);

int
lsquic_conn_crypto_alg_keysize (const lsquic_conn_t *c);

struct lsquic_conn_single
lsquic_conn_open_subflow(lsquic_conn_t *c);

void
lsquic_conn_call_on_new_subconn(const lsquic_conn_t *c);

#endif
