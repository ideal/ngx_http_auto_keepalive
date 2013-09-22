# ngx_auto_keepalive

This module disables keepalive automatically when the http requests are for iso, zip, gz ... files.

Installation Instructions
=========================

Build and install by running in nginx directory:

```
./configure --add-module=/path/to/ngx_http_auto_keepalive
```

Configuration
=============

In main, server or location config:
```
    keepalive_autoclose on;
    autoclose_filetypes ".iso .zip";
```
