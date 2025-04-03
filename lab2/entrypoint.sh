#!/bin/bash

until [ -f /shared/logs/test-results.log ]; do
  sleep 1
done

cp /shared/logs/test-results.log /usr/share/nginx/html/index.html

nginx -g "daemon off;"