project( AFCS.bin )

find_package( OpenCV REQUIRED )

add_executable( AFCS.bin src/main.c src/Mesh.c src/ImageProcessing.c src/Initialization.c)

target_link_libraries( AFCS.bin ${OpenCV_LIBS} )

