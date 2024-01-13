# OopMicrowave, FSM demo for object-oriented university classes
# Alex Anton

project(
    'OopMicrowave',
    'cpp',
    version: '0.1',
    default_options: [
        'warning_level=3',
        'cpp_std=c++20'
    ]
)

include_dirs = include_directories('.', './thirdparty', './include')

imgui_sources = [
    'thirdparty/imgui/imgui_demo.cpp',
    'thirdparty/imgui/imgui_draw.cpp',
    'thirdparty/imgui/imgui_impl_glfw.cpp',
    'thirdparty/imgui/imgui_impl_opengl3.cpp',
    'thirdparty/imgui/imgui_tables.cpp',
    'thirdparty/imgui/imgui_widgets.cpp',
    'thirdparty/imgui/imgui.cpp'
]

glfw_dep = dependency('glfw3', required: true)
glew_dep = dependency('glew', required: true)
gl_dep = dependency('gl', required: true)

imgui = library('imgui',
    imgui_sources,
    dependencies: [ gl_dep, glfw_dep, glew_dep ] ,
    include_directories: include_dirs
)

imgui_dep = declare_dependency(include_directories: include_dirs, link_with: imgui)

deps = [ gl_dep, glew_dep, glfw_dep, imgui_dep ]

sources = [
    'src/app_impl/app_gl.cpp',
    'src/app_impl/builder.cpp',
    'src/base_type/state.cpp',
    'src/context/clock.cpp',
    'src/context/countdown.cpp',
    'src/context/state.cpp',
    'src/entity/gl_window.cpp',
    'src/entity/clock.cpp',
    'src/state/cooking.cpp',
    'src/state/door_closed.cpp',
    'src/state/door_opened.cpp',
    'src/ui/microwave_control.cpp',
    'src/ui/microwave_gl_scene.cpp',
    'src/main.cpp'
]

executable(
    'oop_microwave',
    sources,
    dependencies: deps,
    include_directories: include_dirs
)
