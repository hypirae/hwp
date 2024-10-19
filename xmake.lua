 add_rules("mode.debug", "mode.release")

-- add debug and release modes
add_requires("ncurses")

target("hwp")
    -- set output type
    set_kind("binary")

    -- source files
    add_files("src/*.cxx")

    -- add include directory src/include
    add_includedirs("src/include")


    -- link libraries
    add_packages("ncurses")

    -- compiler flags
    add_cflags("-std=gnu++17")                  -- C++17 + GNU extensions
    add_cflags("-Wall")                         -- Enable all warnings
    add_cflags("-Wextra")                       -- Enable extra warnings
    add_cflags("-Werror")                       -- Treat warnings as errors
    add_cflags("-pedantic")                     -- Be pedantic
    add_cflags("-pedantic-errors")              -- Treat pedantic warnings as errors
    add_cflags("-Wformat=2")                    -- Check format strings
    add_cflags("-Wwrite-strings")               -- Check for write strings
    add_cflags("-Wswitch")                      -- Check for missing switch cases
    add_cflags("-Wshadow")                      -- Check for shadowed variables
    add_cflags("-Wpointer-arith")               -- Check for pointer arithmetic
    add_cflags("-Wstrict-prototypes")           -- Check for strict prototypes
    add_cflags("-Wmissing-prototypes")          -- Check for missing prototypes
    add_cflags("-Wmissing-declarations")        -- Check for missing declarations
    add_cflags("-Wnested-externs")              -- Check for nested externs
    add_cflags("-Winline")                      -- Check for inlined functions
    add_cflags("-Wredundant-decls")             -- Check for redundant declarations
    add_cflags("-fsanitize=address")            -- Address sanitizer
    add_cflags("-fsanitize=leak")               -- Leak sanitizer
    add_cflags("-fsanitize=undefined")          -- Undefined behavior sanitizer
    add_cflags("-fstack-protector")             -- Stack protector

    -- linker flags
    add_ldflags("-fsanitize=address")           -- Address sanitizer
    add_ldflags("-fsanitize=leak")              -- Leak sanitizer
    add_ldflags("-fsanitize=undefined")         -- Undefined behavior sanitizer

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

