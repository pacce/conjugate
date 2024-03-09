project('conjugate', 'cpp', version: '0.1.0', default_options : ['warning_level=3', 'cpp_std=c++20'])

sources       = []
headers       = [include_directories('include')]
dependencies  = []

conjugate_dep = declare_dependency(
    include_directories : headers
  , dependencies        : dependencies
  )


executable('main', 'source/main.cpp', dependencies: [conjugate_dep])

if not meson.is_subproject()
  subdir('tests')
endif
