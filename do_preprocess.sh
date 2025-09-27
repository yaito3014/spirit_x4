#!/usr/bin/sh
cd include/boost/spirit/alloy/detail/preprocessed
g++ -Iinclude -E -P -DBOOST_SPIRIT_ALLOY_GENERATE_PREPROCESSED ../tuple_impl.hpp > temp.hpp
sed -e '/\/\/ replace me/{r temp.hpp' -e 'd}' tuple_impl.hpp.in > tuple_impl.hpp
clang-format -i tuple_impl.hpp
rm temp.hpp
