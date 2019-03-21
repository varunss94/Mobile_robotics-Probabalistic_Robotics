#!/usr/bin/env python

import helper_functions

size = 600
data1 = [None] * 600
data2 = [None] * 600

for i in range(0, size):
    data1[i] = 1.0 / float(size)
    data2[i] = 0.0

for i in range(0, size):
    helper_functions.display_basic(data1, size)
