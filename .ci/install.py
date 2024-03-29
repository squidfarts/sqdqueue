#!/user/bin/env python3
###################################################################################
#                                                                                 #
# NAME: install.py                                                                #
#                                                                                 #
# AUTHOR: Michael Brockus.                                                        #
#                                                                                 #
# CONTACT: <mailto:michael@squidfarts.com>                                        #
#                                                                                 #
# NOTICES:                                                                        #
#                                                                                 #
# License: Apache-2.0                                                             #
#                                                                                 #
###################################################################################
import subprocess
import sys, os

subprocess.call("brew update", shell=True)
subprocess.call("brew install ninja", shell=True)

subprocess.call("pip3 install meson==0.50.0 conan==1.19.0", shell=True)