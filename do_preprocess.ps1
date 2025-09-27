cl.exe /EP /Iinclude /I..\preprocessor\include /DBOOST_SPIRIT_ALLOY_GENERATE_PREPROCESSED include/boost/spirit/alloy/detail/tuple_impl.hpp > include/boost/spirit/alloy/detail/preprocessed/temp.hpp
Push-Location include/boost/spirit/alloy/detail/preprocessed
(Get-Content tuple_impl.hpp.in -Raw) -replace '// replace me', $(Get-Content temp.hpp -Raw) | Set-Content tuple_impl.hpp
clang-format -i tuple_impl.hpp
Remove-Item temp.hpp
Pop-Location
