/* 
 *
 * Copyright (c) 2013 Shang Yuanchun <idealities@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <nginx.h>
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

typedef struct {
    ngx_flag_t    keepalive_autoclose;     /* auto disable keepalive */
} ngx_http_auto_keepalive_loc_conf_t;

static void *create_http_auto_keepalive_loc_conf(ngx_conf_t *cf);
static char *merge_http_auto_keepalive_loc_conf(ngx_conf_t *cf,
                void *parent, void *child);

static ngx_command_t ngx_http_auto_keepalive_commands[] = {

    { ngx_string("keepalive_autoclose"),
      NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|
      NGX_CONF_FLAG,
      ngx_conf_set_flag_slot,    /* set  */
      NGX_HTTP_LOC_CONF_OFFSET,  /* conf */
      0,                         /* offset */
      NULL                       /* post   */
    },

    ngx_null_command
};

static ngx_http_module_t ngx_http_auto_keepalive_module_ctx = {
    NULL, /* preconfiguration  */
    NULL, /* postconfiguration */

    NULL, /* create_main_conf */
    NULL, /* init_main_conf   */

    NULL, /* create_srv_conf  */
    NULL, /* merge_srv_conf   */

    create_http_auto_keepalive_loc_conf,
    merge_http_auto_keepalive_loc_conf
};

ngx_module_t ngx_http_auto_keepalive_module = {
    NGX_MODULE_V1,
    &ngx_http_auto_keepalive_module_ctx,  /* module context  */
    ngx_http_auto_keepalive_commands,     /* module commands */
    NGX_HTTP_MODULE,                      /* module type     */
    NULL,                                 /* init master     */
    NULL,                                 /* init module     */
    NULL,                                 /* init process    */
    NULL,                                 /* init thread     */
    NULL,                                 /* exit thread     */
    NULL,                                 /* exit process    */
    NULL,                                 /* exit master     */
    NGX_MODULE_V1_PADDING
};

static void *create_http_auto_keepalive_loc_conf(ngx_conf_t *cf)
{
    return NULL;
}

static char *merge_http_auto_keepalive_loc_conf(ngx_conf_t *cf,
                void *parent, void *child)
{
    return NULL;
}
