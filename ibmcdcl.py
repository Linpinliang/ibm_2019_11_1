# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 10:15:52 2019

@author: lpl
"""
import numpy as np

import matplotlib.pyplot as plt



name1 = 'Re = '
Re = 78.5
name2 = '_lagrange_node'
name3='.dat'


u = 0.05


time = []
cd = []
positionx = []
#fx = np.loadtxt('Re = 78.5_lagrange_node172.dat', skiprows=1, dtype=float,usecols=(4))
#print(fx)

step_start = 0
step_end =3000
step_internal = 1

stepnumber = np.arange(step_start,step_end,step_internal)


for i in range(len(stepnumber)):
    #print(i)
    name = name1 + str(Re) + name2 + str(stepnumber[i]) +name3
    #print(name)
    fx = np.loadtxt(name, skiprows=1, dtype=float,usecols=(4))
    pos_x =  np.loadtxt(name, skiprows=1, dtype=float,usecols=(0))
    positionx.append(pos_x.mean()-80)   
    #print(fx.sum()*2/40/u/u)
    
    time.append(i)
    cd.append(fx.sum()*2/40/u/u)


 
plt.plot(time,cd,positionx)
plt.show()





















#fy = np.loadtxt('Re = 40_lagrange_node501.dat', skiprows=1, dtype=float,usecols=(5))
#print(fy.sum())
#print(fy.sum())

