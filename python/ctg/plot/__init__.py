# Copyright (c) 2018 Frederik Beaujean
# Copyright (c) 2018 
#
# This file is part of the ctg project. ctg is free software;
# you can redistribute it and/or modify it under the terms of the GNU General
# Public License version 2, as published by the Free Software Foundation.
#
# ctg is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 59 Temple
# Place, Suite 330, Boston, MA  02111-1307  USA

## minimal versions checks
# matplotlib
import matplotlib._version
if matplotlib._version.get_versions()['version'] < '2.0':
    raise ImportError('ctg.plot requires matplotlib in version 2.0 or higher')

from . import config

from .plotter import *
