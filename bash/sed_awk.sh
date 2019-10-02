#!/bin/bash
sed 's/6.30/7.30/g' song.txt  | awk '{print $2}'
