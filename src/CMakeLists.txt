# Build library providing tools for executable
add_library(lgttools mainWindow.cc dataReadThread.cc gaugeCluster.cc gauge.cc )

# Build executable
add_executable(lgtdisplay lgtdisplay.cc)

# Link
target_link_libraries(lgttools Qt5::Core Qt5::Widgets)
target_link_libraries(lgtdisplay lgttools Qt5::Core Qt5::Widgets)

# Install rules
install(TARGETS lgtdisplay DESTINATION bin/lgtdisplay)
