# -*- coding: utf-8 -*-
"""
Created on Mon Jan 13 15:09:57 2025

The purpose of this file is to create samples of data
to test our unique snowflakes example on.

@author: mlgte
"""

import random

numberSnowFlakes:int = 10000;


for i in range(10):
    numberSnowFlakes = random.randint(100, 100000);
    print("Writting file {f}".format(f= "SnowflakeSample_{:0>4}.txt".format(i)));
    with open("SnowflakeSample_{:0>4}.txt".format(i), 'a', newline ='') as file:
        file.write("{:d}\n".format(numberSnowFlakes));
        for j in range(numberSnowFlakes):
            snowflake:str = "{:d} {:d} {:d} {:d} {:d} {:d}".format(random.randint(0, 10000000),
                                                                   random.randint(0, 10000000),
                                                                   random.randint(0, 10000000),
                                                                   random.randint(0, 10000000),
                                                                   random.randint(0, 10000000),
                                                                   random.randint(0, 10000000));
            print("Snowflake {:d} -> {sf}".format(j,sf = snowflake))
            file.write("{sf}\n".format(sf = snowflake));