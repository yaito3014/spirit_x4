#!/usr/bin/sh
g++ -Iinclude -E -P -DBOOST_SPIRIT_ALLOY_GENERATE_PREPROCESSED include/boost/spirit/alloy/detail/tuple_impl.hpp > include/boost/spirit/alloy/detail/preprocessed/temp.hpp
cd include/boost/spirit/alloy/detail/preprocessed
sed -e '/\/\/ replace me/{r temp.hpp' -e 'd}' tuple_impl.hpp.in > tuple_impl.hpp
clang-format -i tuple_impl.hpp
rm temp.hpp
