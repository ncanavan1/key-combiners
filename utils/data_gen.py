import numpy as np
import os

def gen_keys(num_keys,key_size,file):
    keys = []
    for i in range(0,num_keys):
        keys.append(str(np.random.bytes(key_size)))
    
    with open(file, "w") as f:
        for key in keys:
            f.write(key+"\n")
            
##generates 128 bit keys    
gen_keys(100,16,"keys_128bits.txt")

