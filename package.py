# -*- coding: utf-8 -*-

import platform

name = 'xgen-usd'

version = "0.0.0"

author = 'zhusun'

description = 'xgen-usd'

requires = []

def commands():
    env.PYTHONPATH.append("{root}/install/python")
    env.PXR_PLUGINPATH_NAME.append('{root}/install/usd')

format_version = 2
