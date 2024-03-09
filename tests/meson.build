# cmake   = import('cmake')
# options = cmake.subproject_options()
# options.add_cmake_defines({'RC_ENABLE_GTEST': 'ON'})
# 
# rapidcheck_project  = cmake.subproject('rapidcheck', options: options)
# 
# rapidcheck          = rapidcheck_project.dependency('rapidcheck')
# rapidcheck_gtest    = rapidcheck_project.dependency('rapidcheck_gtest')
gtest               = dependency('gtest')

dependencies = [conjugate_dep, gtest]

test('vector-operation', executable('vector-operation', 'vector-operation.cpp', dependencies: dependencies))
test('matrix-operation', executable('matrix-operation', 'matrix-operation.cpp', dependencies: dependencies))
