# CMake generated Testfile for 
# Source directory: /home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces
# Build directory: /home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lint_cmake "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces/test_results/ai4r_interfaces/lint_cmake.xunit.xml" "--package-name" "ai4r_interfaces" "--output-file" "/home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/humble/bin/ament_lint_cmake" "--xunit-file" "/home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces/test_results/ai4r_interfaces/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/humble/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces/CMakeLists.txt;53;ament_package;/home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3.10" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces/test_results/ai4r_interfaces/xmllint.xunit.xml" "--package-name" "ai4r_interfaces" "--output-file" "/home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces/ament_xmllint/xmllint.txt" "--command" "/opt/ros/humble/bin/ament_xmllint" "--xunit-file" "/home/zekaicheong/asclinic-system/ros2_ws/build/ai4r_interfaces/test_results/ai4r_interfaces/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/humble/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/humble/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/humble/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces/CMakeLists.txt;53;ament_package;/home/zekaicheong/asclinic-system/ros2_ws/src/ai4r_interfaces/CMakeLists.txt;0;")
subdirs("ai4r_interfaces__py")
