#!/bin/python3
import os
import subprocess

if __name__=="__main__":
    variations = os.listdir(os.path.dirname(os.path.abspath(__file__)))
    for variation in variations:
         abspath = os.path.abspath(variation)
         if (os.path.isdir(abspath)):
             build_dir = os.path.join(abspath, "build")
             if (os.path.isdir(build_dir)):
                 subprocess.call("make -C {}".format(build_dir), shell = True)
             else:
                 cur_dir = os.getcwd()
                 os.makedirs(build_dir)
                 os.chdir(build_dir)
                 subprocess.call("cmake ../", shell = True)
                 subprocess.call("make", shell = True)
                 os.chdir(cur_dir)





