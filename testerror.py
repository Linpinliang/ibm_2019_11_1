# -*- coding: utf-8 -*-
"""
Created on Fri Oct 25 09:49:29 2019

@author: lpl
"""

import numpy as np

fx1 = np.loadtxt('Re = 20_lagrange_node4000.dat', skiprows=1, dtype=float,usecols=(4))
#print(fx)

fx2 = np.loadtxt('Re = 20_lagrange_node5000.dat', skiprows=1, dtype=float,usecols=(4))

#print(fx)


result = fx1-fx2
#result = result**2
print(result/fx1)