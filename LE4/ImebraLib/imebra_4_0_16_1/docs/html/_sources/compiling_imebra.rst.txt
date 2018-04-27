.. _compiling-imebra-label:

Compiling Imebra
================

This section explains how to compile Imebra from the source distribution.
You can download the source distribution from https://imebra.com, or you can create a source distribution
by following the instructions at :ref:`build-distribution-label`

The result of the Imebra compilation is a shared library for your operating system of choice.

The Imebra Source Distribution includes:

- the source code for the library
- the source code for the tests
- pre-built documentation
- pre-generated JNI headers for Java


Compiling the C++ version of Imebra
-----------------------------------

Prerequisites
.............

In order to build the library from the Imebra Source Distribution you need:

- the source distribution of Imebra, available here: https://imebra.com/get-it/
- a modern C++ compiler (GCC, clang, Visual Studio, etc)
- CMake version 2.8 or newer (https://cmake.org/)




Building Imebra
...............

The library folder contains a CMakeLists file, which contains the information needed by
CMake to generate a solution file for your platform (a make file, a VisualStudio solution, etc).

To generate the Imebra shared library, execute the following steps:

1. Create a folder that will contain the result of the compilation (artifacts)
2. cd into the created artifacts folder
3. execute cmake with the path to the Imebra's library folder as parameter
4. execute cmake with the --build option, and on Windows optionally specify the build configuration

For instance:

::

    md artifacts
    cd artifacts
    cmake imebra_location/library
    cmake --build .

The first CMake command will generate a solution file for the your platform: this will be a 
make file on Linux, a VisualStudio solution of Windows, an XCode project on Mac.

The second CMake command with the --build option will launch make, VisualStudio or the build
chain defined on your machine.


Adding support for the Jpeg2000 decoder
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

Imebra contains an experimental Jpeg2000 decoder which can be used to decompress Jpeg2000 images
embedded into DICOM datasets.

The Jpeg2000 codec depends on the open source library OpenJpeg, available at http://www.openjpeg.org

Both the major versions of openjpeg (1 and 2) are supported.

After you have compiled and installed openjpeg, you must add the following command line options
when launching cmake:

To use the version 1.X of openjpeg::

    DJPEG2000=1

To use the version 2.X of openjpeg::

    DJPEG2000=2

For instance, the complete sequence of commands to build imebra with support for openjpeg 1.X would be::

    md artifacts
    cd artifacts
    cmake DJPEG2000=1 imebra_location/library
    cmake --build .


Windows specific instructions
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

On Windows cmake will, by default, generate a 32 bit solution for the most recent Visual Studio compiler installed on
the system.

Additionally, when specifying the --build option it is possible to specify the debug or relase configuration via
the option "--config Debug" or "--config Release"

It is possible to build a 64 bit version of the library by explicitly specifying a 64 bit generator when launching cmake.

The cmake generators available on Windows include:

- Visual Studio 14 2015 [arch] = Generates Visual Studio 2015 project files.
                                 Optional [arch] can be "Win64" or "ARM".
- Visual Studio 12 2013 [arch] = Generates Visual Studio 2013 project files.
                                 Optional [arch] can be "Win64" or "ARM".
- Visual Studio 11 2012 [arch] = Generates Visual Studio 2012 project files.
                                 Optional [arch] can be "Win64" or "ARM".
- Visual Studio 10 2010 [arch] = Generates Visual Studio 2010 project files.
                                 Optional [arch] can be "Win64" or "IA64".
- Visual Studio 9 2008 [arch]  = Generates Visual Studio 2008 project files.
                                 Optional [arch] can be "Win64" or "IA64".
- Visual Studio 8 2005 [arch]  = Generates Visual Studio 2005 project files.
                                 Optional [arch] can be "Win64".

To generate the 64 bit version of the library just specify the proper generator and architecture.
For instance the following script will compile a Release 64 bit version of imebra using Visual Studio 14 (2015):

::

    mkdir artifacts_64bit_release
    cd artifacts_64bit_release
    cmake -G "Visual Studio 14 2015 Win64" imebra_location/library
    cmake --build . --config Release

The following example will compile a Debug 64 bit version of imebra using Visual Studio 14 (2015):

::

    mkdir artifacts_64bit_debug
    cd artifacts_64bit_debug
    cmake -G "Visual Studio 14 2015 Win64" imebra_location/library
    cmake --build . --config Debug

To generate the 32 bit version of the library, just omit the architecture after the name of the cmake generator:

::

    mkdir artifacts_32bit_debug
    cd artifacts_32bit_debug
    cmake -G "Visual Studio 14 2015" imebra_location/library
    cmake --build . --config Debug


OS-X/iOS specific instructions
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

On Mac, CMake will generate a build for OS-X. In order to generate a build of iOS you have to add one of
the following arguments::

    -DIOS=IPHONE

or::

    -DIOS=SIMULATOR

The first flag forces CMake to generate a library for iPhone (real hardware), while the second forces CMake
to generate a library for the iPhone simulator.

To generate a library for OS-X, type the following (replace imebra_location with the path to Imebra):

::

    mkdir imebra_for_osx
    cd imebra_for_osx
    cmake imebra_location/library
    cmake --build .

To generate a library for iPhone, type the following (replace imebra_location with the path to Imebra):

::

    mkdir imebra_for_ios
    cd imebra_for_ios
    cmake imebra_location/library -DIOS=IPHONE
    cmake --build .

.. seealso:: iOS applications based on Imebra need to be linked also with libiconv.a or libiconv.tbd.

To generate a library for the iPhone simulator, type the following (replace imebra_location with the path to Imebra):

::

    mkdir imebra_for_ios
    cd imebra_for_ios
    cmake imebra_location/library -DIOS=SIMULATOR
    cmake --build .

.. seealso:: iOS applications based on Imebra need to be linked also with libiconv.a or libiconv.tbd.

To generate a project that can be opened with XCode append the argument -G xcode (replace imebra_location with the path to Imebra):

::

    mkdir xcode_project
    cd xcode_project
    cmake imebra_location/library -G xcode


Compiling the Android version of Imebra
---------------------------------------

Prerequisites
.............

In order to build the Android version of Imebra you need:

- the source distribution of Imebra, available here: https://imebra.com/get-it/
- Apache Ant
- the Android SDK
- the Android NDK

Building Imebra
...............

The Android version of the library needs both the Java source code (located in the wrappers/javaWrapper folder)
and the C++ source code (located in the library folder)

To generate the Imebra Jar library:

1. cd into the Imebra wrappers/javaWrapper folder
2. run ant and define the properties sdk.dir and ndk.dir so they point to the home folders of the Android SDK and NDK respectively
3. the produced JAR will be located in the folder wrappers/javaWrapper/out/artifacts

For instance:

::

    cd wrappers/javaWrapper
    ant -Dsdk.dir=path/to/Android/SDK -Dndk.dir=path/to/Android/NDK
    


Compiling the Python version of Imebra
--------------------------------------

Prerequisites
.............

In order to build Imebra for Python you need:

- Python installed
- setuptools

Building Imebra
...............

The root folder of the source distribution contains the setup.py file necessary to build and install Imebra for Python.

In order to build and install Imebra for Python:

- cd into the root folder of the Imebra Source Distribution
- run the setup.py file with the install option (requires administrator privileges):

::

    cd imebra
    python setup.py install

To remove the Python version of Imebra from your system:

::

    pip uninstall imebra


Compiling the test units
------------------------

Prerequisites
.............

In order to build and execute the tests you need:

- a compiled gtest library and its include file (get it here https://github.com/google/googletest)
- the compiled C++ version of Imebra

Building the tests
..................

To compile te tests, execute the following steps:

1. create a folder that will contain the test units executable
2. cd into the created folder
3. run cmake with the path to the tests/CMakeLists.txt as a parameter. You can also define the
   CMake variables imebra_library, gtest_library and gtest_include with the path to the
   imebra library, gtest library and gtest include folder respectively
4. run cmake --build .

For instance:

::

    md tests_artifacts
    cd tests_artifacts
    cmake -Dimebra_library="path/to/imebra/library" -Dgtest_library="path/to/gtest/library" -Dgtest_include="path/to/gtest/include" imebra_location/tests
    cmake --build .






