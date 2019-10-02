#!/bin/bash
while read LINE; do echo "$LINE" | cut -f1 -d":"; done < /etc/passwd
