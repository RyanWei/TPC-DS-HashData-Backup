#/bin/bash

logfilename=$(date +%Y%m%d)_$(date +%H%M%S)
nohup sh tpcds.sh > tpcds.$logfilename.log 2>&1 &