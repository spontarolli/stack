#!/usr/bin/env python
# -*- coding: utf-8 -*-

import psutil
import math
import sys

def get_maxmem():

    mem = psutil.avail_phymem()

    sl = []
    i = 0
# some magic 1024 - overhead of string object
    fill_size = 1024
    if sys.version.startswith('2.7'):
        fill_size = 1003
    if sys.version.startswith('3'):
        fill_size = 497

    fill_size *= 1024
    MiB = 0
    while True:
        max_mem = mem/1024/1024*0.8
        if MiB > max_mem: break
        s = str(i).zfill(fill_size)
        sl.append(s)
        i += 1
        # MiB += 1024
        MiB += 1
    return MiB*1024*1024

def fatiador(shape,nfiles):
    h,w,c = shape
    print h,w,c
    max_usable = get_maxmem()*0.6
    print 'max_usable', max_usable
    mem_per_line = w*c*nfiles
    print 'mem_per_line', mem_per_line
    max_lines = max_usable/mem_per_line
    print 'max_lines', max_lines
    max_lines = int(max_lines)
    print 'max_lines', max_lines
    fatias = range(0,h,max_lines) + [h]
    print 'fatias', fatias
    return fatias


