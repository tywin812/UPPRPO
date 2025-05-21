#!/bin/bash

until kubectl get pods -l app=app-service -o jsonpath='{.items[0].status.phase}' | grep Running; do
  sleep 1
done

APP_POD=$(kubectl get pods -l app=app-service -o jsonpath='{.items[0].metadata.name}')
until [ -n "$(kubectl logs $APP_POD)" ]; do
  sleep 1
done

LOGS=$(kubectl logs $APP_POD)
echo "<pre>$LOGS</pre>" > /usr/share/nginx/html/index.html
nginx -g "daemon off;"