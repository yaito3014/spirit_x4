# Copyright 2025 Yaito Kakeyama
#
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

add_executable(alloy_tuple_test)

target_sources(alloy_tuple_test PRIVATE tuple.cpp)

target_link_libraries(
    alloy_tuple_test
    PRIVATE Boost::spirit_x4 boost_spirit_x4_cxx_test
)

add_test(NAME alloy_tuple_test COMMAND alloy_tuple_test)
