# -*- coding: utf-8 -*-
"""
Created on Wed May 13 13:05:42 2015

@author: durians
"""
print 'hello','python'

#查看帮助
#type() 			查看变量类型
#dir(math) 			查看类支持的函数
#help(math.sin)		查看函数帮助文档，q退出查看

#输入输出
#raw_input()		输入函数
#print            输出函数

print type("hello")
print type(1.24)
print type(5)
print type(True)


print 1 + 2
print '1' + '2'
print 1231231231231234324234342534534342342342342342 + 1
print False + 5.0

import math
print dir(math)
help(math.cos)


#字符串读入raw_input()
pi = 3.14
radius = float(raw_input('Radius:'))
area = pi * radius * radius
print 'The circle area is' ,  area


#练习
x = 7.0
y = 5
print x%y

print not bool(int(raw_input()) % 2)

#时间输出
import time
now = int(time.time())
print now
ta = time.localtime(now)
print ta
ft = time.strftime("%Y-%m-%d %H:%M:%S",ta)
print ft

import datetime
today = datetime.date.today()
print today

