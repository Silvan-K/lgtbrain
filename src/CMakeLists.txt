# Build library providing tools for executable
add_library(lgttools mainWindow.cc
		     dummyDataReadThread.cc
		     dataReadThread.cc
		     gaugeCluster.cc
		     LCDGauge.cc
		     CumulativeLCDGauge.cc
		     barGauge.cc
		     bar.cc)

# Build executable
add_executable(lgtdisplay lgtdisplay.cc)

# Link
target_link_libraries(lgttools Qt5::Widgets subarussm)
target_link_libraries(lgtdisplay lgttools Qt5::Widgets)

# Install rules
install(TARGETS lgtdisplay DESTINATION bin/lgtdisplay)
