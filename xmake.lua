add_rules("mode.debug", "mode.release")

add_requires("ncurses")

target("hwp")
    set_kind("binary")
    add_files("src/*.c")
    add_packages("ncurses")
    add_cflags("-std=c99")
    add_cflags("-Wall")
    add_cflags("-Wextra")
    add_cflags("-Werror")
    add_cflags("-Wno-unused")
    add_cflags("-pedantic")
    add_cflags("-pedantic-errors")
    add_cflags("-Wformat=2")
    add_cflags("-Wno-format-nonliteral")
    add_cflags("-Wno-format-security")
    add_cflags("-Wno-missing-format-attribute")
    add_cflags("-Wwrite-strings")
    add_cflags("-Wswitch")
    add_cflags("-Wshadow")
    add_cflags("-Wcast-qual")
    add_cflags("-Wcast-align")
    add_cflags("-Wpointer-arith")
    add_cflags("-Wbad-function-cast")
    add_cflags("-Wstrict-prototypes")
    add_cflags("-Wmissing-prototypes")
    add_cflags("-Wmissing-declarations")
    add_cflags("-Wnested-externs")
    add_cflags("-Winline")
    add_cflags("-Wredundant-decls")
    add_cflags("-Wold-style-definition")
    add_cflags("-Wno-variadic-macros")
    add_cflags("-Wno-long-long")
    add_cflags("-Wno-overlength-strings")
    add_cflags("-Wno-packed")
    add_cflags("-fsanitize=address")
    add_cflags("-fsanitize=leak")
    add_cflags("-fsanitize=undefined")
    add_cflags("-fstack-protector")
    add_ldflags("-fsanitize=address")
    add_ldflags("-fsanitize=leak")
    add_ldflags("-fsanitize=undefined")


--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

