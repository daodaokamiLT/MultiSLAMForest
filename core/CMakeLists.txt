add_library(multislam_manager multislam_manager.cpp)

target_link_libraries(multislam_manager ${dependency} ) #multislamforest)

add_subdirectory(test)