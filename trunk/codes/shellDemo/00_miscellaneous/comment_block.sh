#!/bin/bash
#注释shell的一段代码
#set -x
#set -v
:<<COMMENTBLOCK
echo good
echo good2
echo good3
COMMENTBLOCK
#set +x
echo good4
echo good5
echo good6
echo good7

