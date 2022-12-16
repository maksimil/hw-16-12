workspace "poly"
   configurations { "Debug", "Release" }

project "poly"
   kind "ConsoleApp"
   language "C++"

   files {"main.cpp", "poly.hpp"}
   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"

project "poly_test"
   kind "ConsoleApp"
   language "C++"

   links {"gtest", "pthread"}
   includedirs {"/usr/loca/include"}

   files {"*_test.cpp", "poly.hpp"}
   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"  
