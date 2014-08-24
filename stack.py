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

def nditer_mean(data, axes):
    it = np.nditer([data, None],
            flags=['reduce_ok','external_loop'],
            op_flags=[['readonly'], ['readwrite', 'allocate']],
            op_axes=axes)
    it.operands[1][...] = 0
    for x, y in it:
#        print x,y
        y[...] += x.mean()
    return it.operands[1]

# def nditer_diff_square(data,mean,out, axes):
#     it = np.nditer([data,mean, out],
#             flags=['reduce_ok','external_loop'],
#             op_flags=[['readonly'],['readonly'], ['readwrite', 'allocate']],
#             op_axes=axes)
#     it.operands[2][...] = 0
#     for x, y, z in it:
# #        print x,y,z
#         z[...] = (x - y)
#     return it.operands[2]
#

def square(a, out=None):
    it = np.nditer([a, out],
        flags = ['external_loop', 'buffered'],
        op_flags = [['readonly','no_broadcast'],
                    ['writeonly', 'allocate', 'no_broadcast']])
    for x, y in it:
        w = x
        print x
        mean = x.mean()
        print mean
        y[...] = w
    return it.operands[1]


def nditer_kappasigma(data, out, axes):
    it = np.nditer([data, out],
            flags=['reduce_ok','external_loop'],
            op_flags=[['readonly'],['readwrite', 'allocate']],
            op_axes=axes,
#            order='F'
            )
    it.operands[1][...] = 0
    for x, z in it:
        print x.shape,z.shape,x,z
#        print w
#        mean = x.mean()
#        sigma  = np.sqrt(((x - mean)**2).mean()).mean()
#        print mean, sigma
#        y = np.where(x < mean - (sigma*kappa),mean,x)
#        print y
#        w = np.where(y > mean + (sigma*kappa),mean,y)
#        print w
#        raw_input()
        z[...] = x
    return it.operands[1]

## orig.shape = ?,?,3 - nditer_mean(orig,[None,[0,1,-1]])
## orig.shape = ?,?,3 - nditer_diff_square(orig,mean,out_orig_like,[[0,1,2],[0,1,-1],[0,1,2]])

# tt = time.time()
# colors = [rs,gs,bs]
# for c,color in enumerate(colors):
#     t0 = time.time()
#     for n in xrange(niter):
#         color = nditer_kappasigma(color,[[0,1,2],[0,1,2]])
#     color = nditer_mean(color,[None,[0,1,-1]])
#     colors[c] = color
#     print time.time() - t0
# final = np.dstack(colors)
# Image.fromarray(final.astype('uint8')).save('final_new.tiff')
# print "total time:", (time.time()-tt)

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


# final = np.zeros_like(ref)
# tt = time.time()
# for c,color in enumerate((rs,gs,bs)):
#     for i,d23 in enumerate(color):
#         t1 = time.time()-t0
# #         print "\r color:%s x:%4s time:%8.6f" % (c,i,t1),
# #        t0 = time.time()
#         for j,d3 in enumerate(d23):
# #             tmp = d3.copy()
#             tmp = d3.copy()
#             for n in xrange(niter):
#                 tmp.sort()
#                 mean = tmp.mean()
# #                median = tmp[median_list]
#                 median = mean
#                 tmp = (tmp - mean)**2
#                 sigma = np.sqrt(tmp.mean())
# #                 sigma = np.std(tmp)
#                 tmp = np.where(tmp > mean - (sigma*kappa),tmp,median)
#                 tmp = np.where(tmp < mean + (sigma*kappa),tmp,median)
#             final[i,j,c] = tmp.mean()
# Image.fromarray(final.astype('uint8')).save('final.tiff')
# print "total time:", (time.time()-tt)

# Image.fromarray(sigma.astype('uint8')).save('sigma.tiff')
# Image.fromarray(upper.astype('uint8')).save('upper.tiff')
# Image.fromarray(lower.astype('uint8')).save('lower.tiff')

