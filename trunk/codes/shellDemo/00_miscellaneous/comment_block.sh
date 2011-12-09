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
:<<BLOCK
echo good5
echo good6
BLOCK
echo good7

