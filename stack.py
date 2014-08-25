#!/usr/bin/env python
# -*- coding: utf-8 -*-

from PIL import Image, ImageChops
import glob
import numpy as np
import sys
import time
import slib

#print sys.argv[1]
#imgList = glob.glob(sys.argv[1])
imgList = sys.argv[1:]
#print imgList
nlist = 200 #len(imgList)
# nlist = len(imgList)
median_list = nlist/2
niter = 2
kappa = 2

#print len(imgList)

ref = np.asarray(Image.open(imgList[0])).astype('uint8')
rs,gs,bs = np.split(ref,[1,2],axis=2)

for c, img in enumerate(imgList[1:nlist]):
    print "\r" + str(c),
    tmpimg = np.asarray(Image.open(img)).astype('uint8')
    rt,gt,bt = np.split(tmpimg,[1,2],axis=2)
    rs = np.dstack((rs,rt))
    gs = np.dstack((gs,gt))
    bs = np.dstack((bs,bt))

rf = rs.copy()
gf = gs.copy()
bf = bs.copy()

print ref.shape

tt = time.time()
colors = [rs,gs,bs]
print rs.shape
print gs.shape
print bs.shape
for c,color in enumerate(colors):
    t0 = time.time()
    print color.shape
    color = slib.kappasigma(color,niter,kappa).astype('uint8')
    print color.shape
#    colors[c] = nditer_mean(color,[None,[0,1,-1]])
    colors[c] = color
    print c
    print time.time() - t0
final = np.dstack(colors)
Image.fromarray(final.astype('uint8')).save('final_new.tiff')
print "total time:", (time.time()-tt)


# Image.fromarray(sigma.astype('uint8')).save('sigma.tiff')
# Image.fromarray(upper.astype('uint8')).save('upper.tiff')
# Image.fromarray(lower.astype('uint8')).save('lower.tiff')

