.. _changes-log-label:

Changes log
===========

Version |release| (this version)
--------------------------------

- Fixed bug #219 (When writing sequences that embed sequences, the item length is wrong) as per SOP :ref:`FIXBUG_2`

Version 4.0.15.1
----------------

- Fixed bug #214 (The lossless jpeg codec should not encode/decode the amplitude only 
  when the amplitude length is 16) as per SOP :ref:`FIXBUG_2`

Version 4.0.14.1
----------------

- Fixed bug #205 (Lossless jpeg codec wrongly writes/reads amplitude value when the amplitude length is equal to the max bit depth) as per SOP :ref:`FIXBUG_2`

Version 4.0.13.1
----------------

- Fixed bug #184 (Remove variable bStopped from dicomStreamCodec::parseStream) as per SOP :ref:`FIXBUG_2`
- Implemented enhancement #199 (Specify that on OS-X and iOS the iconv library must be explicitly linked when using a static Imebra library) as
  per SOP :ref:`DEVENH_2`
- Fixed bug #201 (The build system fails to upload the artifacts to dropbox) as per SOP :ref:`FIXBUG_2`
- Fixed bug #202 (The Specific Charset Tag is populated even when not necessary) as per SOP :ref:`FIXBUG_2`

Version 4.0.12.1
----------------

- Implemented enhancement #187 (Modify the virtual streams so no seek is necessary when streamReader::getReader() is called) as per SOP :ref:`DEVENH_2`
- Fixed bug #188 (The build fails when uploading the artifacts to dropbox) as per SOP :ref:`FIXBUG_2`
- Fixed bug #189 (Remove warnings C4275 and C4251from Windows builds) as per SOP :ref:`FIXBUG_2`
- Fixed bug #192 (Test with corrupted files does not run on Windows) as per SOP :ref:`FIXBUG_2`
- Fixed bug #200 (The attribute with VR AT should be 4 bytes wide, but instead is treated as a 2 bytes attribute) as per SOP :ref:`FIXBUG_2`

Version 4.0.11.2
----------------

- Fixed bug #160 (Replace "Java++" with "Java" in the section "Getting started" of the documentation) as per SOP :ref:`FIXBUG_2`
- Implemented enhancement #182 (Add a section that explains how to download Imebra) as per SOP :ref:`DEVENH_2`

Version 4.0.11.1
----------------

- Fixed bug #177 (Imebra cannot read private tags for implicit VR syntax) as per SOP :ref:`FIXBUG_2`
- Fixed bug #181 (The implementation classes baseStreamInput, baseStreamOutput, readingDataHandler, 
  transform don't provide a virtual destructor) as per SOP :ref:`FIXBUG_2`

Version 4.0.10.1
----------------

- Fixed bug #163 (DrawBitmap fails with 16 bits palette images) as per SOP :ref:`FIXBUG_2`
- Implemented enhancement #164 (Remove warnings "control reaches end of non-void function" in bufferImpl.cpp) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #167 (Remove compilation warning conversion from float/double to int in dataHandlerNumericImpl.h) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #168 (Remove warning VOILUTImpl.h:194:82: conversion to 'double' from 'int64_t') as per SOP :ref:`DEVENH_2`
- Implemented enhancement #169 (Separate the stream codecs from the image codecs) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #172 (Add an experimental jpeg2000 decoder)
- Implemented enhancement #173 (Add the color spaces YBR_ICT and YBR_RCT) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #175 (Accept string tags that pad the value with 0x0 instead of spaces) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #176 (Add internal method streamReader readSome) as per SOP :ref:`DEVENH_2`

Version 4.0.9.1
---------------

- Implemented enhancement #161 (Add the full license text in the project root folder, add a short link to the license in each 
  source file) as per SOP :ref:`DEVENH_2`
- Fixed bug #162 (Dataset: useless copy when inserting non encapsulated images) as per SOP :ref:`FIXBUG_2`

Version 4.0.8.1
---------------

- Implemented enhancement #153 (Modify swig.i so a Python wrapper can be generated with swig) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #154 (Add a objective-c helper that return an UIImage or NSImage) as per SOP :ref:`DEVENH_2`
- Fixed bug #155 (Empty embedded datasets should not be written) as per SOP :ref:`FIXBUG_2`
- Fixed bug #156 (getSequenceItem throws MissingDataElementError instead of MissingItemError) as per SOP :ref:`FIXBUG_2`

Version 4.0.7.1
---------------

- Fixed bug #150 (Missing documentation for Tag members that return numeric and raw data handlers) as per SOP :ref:`FIXBUG_2`
- Fixed bug #151 (Imebra creates the tag 0028,0006 even when the number of color channel is 1) as per SOP :ref:`FIXBUG_2`

Version 4.0.6.1
---------------

- Fixed bug #132 (Dead assignment to runLength in the Jpeg codec) as per SOP :ref:`FIXBUG_2`
- Fixed bug #143 (The documentation wrongly states that Image::Image() allocates the image memory) as per SOP :ref:`FIXBUG_2`
- Implemented enhancement #144 (Improve the bug fixing/feature implementation SOPs so they are developed in separate branches).
  Improved SOPs FIXBUG (:ref:`FIXBUG_2`) DEVFEAT (:ref:`DEVFEAT_2`) DEVENH (:ref:`DEVENH_2`), updated SOP RELEASE (:ref:`RELEASE_2`)
  as per SOPs :ref:`MODSOP_1`, :ref:`DEVENH_1`
- Fixed bug #145 (In the SOP CHGLOG/1 the text

  ::
  
      Version |release| (this version)

  is replaced with the current version) as per SOP :ref:`FIXBUG_2`
- Implemented enhancement #146 (Explain how to compile the 64bit version of the library on Windows) as per SOP :ref:`DEVENH_2`
- Implemented enhancement #148 (Modify CMake for iOS target) as per SOP :ref:`DEVENH_2`

Version 4.0.5.3
---------------

- Fixed bug #117 (build fails on OSX)

Version 4.0.5.1
---------------

- Fixed bug #135 (openFile failure) as per :ref:`FIXBUG_1`
- Implemented enhancement #138 (Redundant check in dicomCodec::allocChannels) as per :ref:`DEVENH_1`
- Fixed bug #139 (On Windows the preprocessor macro NOMINMAX has to be defined if windows.h is included) as per :ref:`FIXBUG_1`
- Implemented enhancement #140 (Remove the macro NOMINMAX from the Imebra source code and place it in CMake) as per :ref:`DEVENH_1`
- Fixed bug #142 (The DICOM VR "LT" (long text) should not treat the backslash as a separator) as per :ref:`FIXBUG_1`

Version 4.0.4.1
---------------

- Fixed bug #131 (Unused variables in transformImpl.cpp) as per :ref:`FIXBUG_1`
- Fixed bug #136 (Segmentation fault when navigating the DicomDir entries) as per :ref:`FIXBUG_1`
- Fixed bug #137 (The example DicomDirItems throws an exception while scanning the DicomDirEntry tags) as per :ref:`FIXBUG_1`

Version 4.0.3.5
---------------

- Fixed bug #134 (The example ChangeTransferSyntax copies the tags over the images created using the new transfer syntax)
- Added XSD file for the imebra_requirements.xml file
- Added Standard Operating Procedures for future development

Version 4.0.3.1
---------------

- Implemented enhancement #130 (Allow the decompression of Jpeg images that have a premature EOI tag)

Version 4.0.2.6
---------------

- Fixed bug #125 (Documentation: The Java examples use the methods setUnicodeString and getUnicodeString and finalize)
- Fixed bug #126 (Documentation: Wrong call to getLut in the examples)
- Fixed bug #127 (Documentation: wrong Java Example for writing a Tag into a DataSet)
- Fixed bug #129 (Documentation: The example that retrieves the LUTs out never exit from the loop)

Version 4.0.2.1
---------------

- Fixed bug #122 (Failure to open a file with Java Wrappers)
- Fixed bug #123 (SWIG translates the Java String to UTF16 and not UTF32 when filling std::wstring)
- Fixef bug #124 (Java charset conversion fails)

Version 4.0.1.6
---------------

- Fixed bug #121 (Wrong Java examples in the documentation)
- Improved test units
- Improved the documentation for the class DataSet
- Improved the section "Compiling Imebra" of the documentation

Version 4.0.1.1
---------------

- Fixed bug #119 (Imebra does not create the tag 0002,0001 when writing a DICOM file)
- Fixed bug #120 (When creating an empty DataSet with unspecified transfer syntax then the transfer syntax is set to 1.2.840.10008.1.2.1)
- Added changes log

Version 4.0.0.11
----------------

- Added test for TransformsChain
- Improved string data handler tests
- Added test for VR UC
- Improved documentation

Version 4.0.0.8
---------------

- Documentation: renamed "Quick tour" to "Getting started"
- Closed bug #118 (Risks in the documentation are not ordered by mitigated total risk)

Version 4.0.0.6
---------------

- Improved documentation
- CMake: when compiling on Windows set the Kernel32 library in the compiler detection block, not in the charset conversion detection block

Version 4.0.0.4
---------------

- First public release of Imebra V4


