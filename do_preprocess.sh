#!/usr/bin/sh
g++ -Iinclude -E -P -DBOOST_SPIRIT_ALLOY_GENERATE_PREPROCESSED include/boost/spirit/alloy/detail/tuple_impl.hpp | tee include/boost/spirit/alloy/detail/preprocessed/tuple_impl.hpp
