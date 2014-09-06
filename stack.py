#!/usr/bin/env python
# -*- coding: utf-8 -*-

import glob
import numpy as np
import sys
import time
import slib
import cv2
import libgeral
import psutil
import math
import sys

def get_maxmem():
    mem = psutil.avail_phymem()
    sl = []
    i = 0
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

def get_slices(shape,nfiles):
    h,w,c = shape
#    print h,w,c
    max_usable = get_maxmem()*0.6
#    print 'max_usable', max_usable
    mem_per_line = w*c*nfiles
#    print 'mem_per_line', mem_per_line
    max_lines = max_usable/mem_per_line
#    print 'max_lines', max_lines
    max_lines = int(max_lines)
#    print 'max_lines', max_lines
    fatias = range(0,h,max_lines)[1:]
#    print 'fatias', fatias
    return fatias


def generate_rgb(imglist):
    ref = cv2.imread(imglist[0])
    rs,gs,bs = np.split(ref,[1,2],axis=2)

    for c, img in enumerate(imglist[1:nlist]):
        tmpimg = cv2.imread(img)
        rt,gt,bt = np.split(tmpimg,[1,2],axis=2)
        rs = np.dstack((rs,rt))
        gs = np.dstack((gs,gt))
        bs = np.dstack((bs,bt))
    return rs,gs,bs

def ksigma(rs,gs,bs):
    colors = [rs,gs,bs]
    for c,color in enumerate(colors):
        t0 = time.time()
        print color.shape
        color = slib.kappasigma(color,niter,kappa).astype('uint8')
        print color.shape
        colors[c] = color
        print time.time() - t0
    final = np.dstack(colors)
    return final

def slice_it(imgobj,slices):
    return np.split(imgobj,slices,axis=0)

def slice_all(imglist):
    ref = cv2.imread(imglist[0])
    slices = get_slices(ref.shape,len(imglist))
    nslices  = len(slices)
    if nslices == 0: return nslices
    for img in imglist:
        imgsliced = slice_it(img,slices)
        for nslice, imgslices in enumerate(imgsliced):
            imgslices.dump(img+str(nslice))


if __name__ == "__main__":
    tt = time.time()
    imglist = glob.glob(sys.argv[1])
    nlist = len(imglist)
    median_list = nlist/2
    niter = 2
    kappa = 2
    rs,gs,bs = generate_rgb(imglist)
    master = ksigma(rs,gs,bs)
    cv2.imwrite('master.tiff',master)
    print "total time:", (time.time()-tt)


