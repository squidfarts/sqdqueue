###################################################################################
#                                                                                 #
# NAME: lib/meson.build                                                           #
#                                                                                 #
# AUTHOR: Michael Brockus.                                                        #
#                                                                                 #
# CONTACT: <mailto:michael@squidfarts.com>                                        #
#                                                                                 #
# NOTICES:                                                                        #
#                                                                                 #
# License: Apache 2.0 :http://www.apache.org/licenses/LICENSE-2.0                 #
#                                                                                 #
###################################################################################



sqdqueue_dir = include_directories('.')

sqdqueue_lib = static_library(meson.project_name(), 
    sources: 'queue.c',
    include_directories: sqdqueue_dir)

sqdqueue_dep = declare_dependency(
    version: meson.project_version(),
    link_with: sqdqueue_lib,
    include_directories: sqdqueue_dir)