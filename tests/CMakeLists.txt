# ==============================================================================
# Copyright 2026 [EterniaLogic]
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# NOTICE: This sub-project integrates the Google Gemini API.
# Usage is subject to the Google AI Terms of Service:
# https://ai.google.dev/terms
# ==============================================================================


# 1. Get GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
# For Windows compatibility
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Add your modern GoogleTests
add_executable(NewTests "Data/CharStringTest.cpp")
target_link_libraries(NewTests PRIVATE Eternia gtest_main)

# 3. Discover them
include(GoogleTest)
gtest_discover_tests(NewTests)
