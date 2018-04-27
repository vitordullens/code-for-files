Exceptions
==========

This section describes the exception classes thrown by Imebra.

The ExceptionManager allows to retrieve the stack trace related to the last thrown Imebra exception.


ExceptionsManager
-----------------
.. doxygenclass:: imebra::ExceptionsManager
   :members:

MissingDataElementError
-----------------------
.. doxygenclass:: imebra::MissingDataElementError
   :members:

MissingGroupError
-----------------
.. doxygenclass:: imebra::MissingGroupError
   :members:
   
MissingTagError
---------------
.. doxygenclass:: imebra::MissingTagError
   :members:

MissingBufferError
------------------
.. doxygenclass:: imebra::MissingBufferError
   :members:

MissingItemError
----------------
.. doxygenclass:: imebra::MissingItemError
   :members:

StreamError
-----------
.. doxygenclass:: imebra::StreamError
   :members:

StreamOpenError
---------------
.. doxygenclass:: imebra::StreamOpenError
   :members:

StreamReadError
---------------
.. doxygenclass:: imebra::StreamReadError
   :members:

StreamWriteError
----------------
.. doxygenclass:: imebra::StreamWriteError
   :members:

StreamCloseError
----------------
.. doxygenclass:: imebra::StreamCloseError
   :members:

DictionaryError
---------------
.. doxygenclass:: imebra::DictionaryError
   :members:

DictionaryUnknownTagError
-------------------------
.. doxygenclass:: imebra::DictionaryUnknownTagError
   :members:

DictionaryUnknownDataTypeError
------------------------------
.. doxygenclass:: imebra::DictionaryUnknownDataTypeError
   :members:

CharsetConversionError
----------------------
.. doxygenclass:: imebra::CharsetConversionError
   :members:

CharsetConversionNoTableError
-----------------------------
.. doxygenclass:: imebra::CharsetConversionNoTableError
   :members:

CharsetConversionNoSupportedTableError
--------------------------------------
.. doxygenclass:: imebra::CharsetConversionNoSupportedTableError
   :members:

CharsetListDiffDefaultError
---------------------------
.. doxygenclass:: imebra::CharsetListDiffDefaultError
   :members:

CodecError
----------
.. doxygenclass:: imebra::CodecError
   :members:

CodecWrongFormatError
---------------------
.. doxygenclass:: imebra::CodecWrongFormatError
   :members:

CodecCorruptedFileError
-----------------------
.. doxygenclass:: imebra::CodecCorruptedFileError
   :members:

CodecWrongTransferSyntaxError
-----------------------------
.. doxygenclass:: imebra::CodecWrongTransferSyntaxError
   :members:

CodecImageTooBigError
---------------------
.. doxygenclass:: imebra::CodecImageTooBigError
   :members:

InvalidSequenceItemError
------------------------
.. doxygenclass:: imebra::InvalidSequenceItemError
   :members:

DataHandlerError
----------------
.. doxygenclass:: imebra::DataHandlerError
   :members:

DataHandlerConversionError
--------------------------
.. doxygenclass:: imebra::DataHandlerConversionError
   :members:

DataHandlerCorruptedBufferError
-------------------------------
.. doxygenclass:: imebra::DataHandlerCorruptedBufferError
   :members:

DataHandlerInvalidDataError
---------------------------
.. doxygenclass:: imebra::DataHandlerInvalidDataError
   :members:

DataSetError
------------
.. doxygenclass:: imebra::DataSetError
   :members:

DataSetDifferentFormatError
---------------------------
.. doxygenclass:: imebra::DataSetDifferentFormatError
   :members:

DataSetUnknownTransferSyntaxError
---------------------------------
.. doxygenclass:: imebra::DataSetUnknownTransferSyntaxError
   :members:

DataSetWrongFrameError
----------------------
.. doxygenclass:: imebra::DataSetWrongFrameError
   :members:

DataSetOldFormatError
---------------------
.. doxygenclass:: imebra::DataSetOldFormatError
   :members:

DataSetImageDoesntExistError
----------------------------
.. doxygenclass:: imebra::DataSetImageDoesntExistError
   :members:

DataSetImagePaletteColorIsReadOnly
----------------------------------
.. doxygenclass:: imebra::DataSetImagePaletteColorIsReadOnly
   :members:

DataSetCorruptedOffsetTableError
--------------------------------
.. doxygenclass:: imebra::DataSetCorruptedOffsetTableError
   :members:

DicomDirError
-------------
.. doxygenclass:: imebra::DicomDirError
   :members:

DicomDirCircularReferenceError
------------------------------
.. doxygenclass:: imebra::DicomDirCircularReferenceError
   :members:

DicomDirUnknownDirectoryRecordTypeError
---------------------------------------
.. doxygenclass:: imebra::DicomDirUnknownDirectoryRecordTypeError
   :members:

HuffmanError
------------
.. doxygenclass:: imebra::HuffmanError
   :members:

HuffmanCreateTableError
-----------------------
.. doxygenclass:: imebra::HuffmanCreateTableError
   :members:

HuffmanReadError
----------------
.. doxygenclass:: imebra::HuffmanReadError
   :members:

HuffmanWriteError
-----------------
.. doxygenclass:: imebra::HuffmanWriteError
   :members:

ImageError
----------
.. doxygenclass:: imebra::ImageError
   :members:

ImageUnknownDepthError
----------------------
.. doxygenclass:: imebra::ImageUnknownDepthError
   :members:

ImageUnknownColorSpaceError
---------------------------
.. doxygenclass:: imebra::ImageUnknownColorSpaceError
   :members:

ImageInvalidSizeError
---------------------
.. doxygenclass:: imebra::ImageInvalidSizeError
   :members:

TransformError
--------------
.. doxygenclass:: imebra::TransformError
   :members:

TransformInvalidAreaError
-------------------------
.. doxygenclass:: imebra::TransformInvalidAreaError
   :members:

TransformDifferentHighBitError
------------------------------
.. doxygenclass:: imebra::TransformDifferentHighBitError
   :members:

ColorTransformError
-------------------
.. doxygenclass:: imebra::ColorTransformError
   :members:

ColorTransformWrongColorSpaceError
----------------------------------
.. doxygenclass:: imebra::ColorTransformWrongColorSpaceError
   :members:

ColorTransformsFactoryError
---------------------------
.. doxygenclass:: imebra::ColorTransformsFactoryError
   :members:

ColorTransformsFactoryNoTransformError
--------------------------------------
.. doxygenclass:: imebra::ColorTransformsFactoryNoTransformError
   :members:

TransformHighBitError
---------------------
.. doxygenclass:: imebra::TransformHighBitError
   :members:

TransformHighBitDifferentColorSpacesError
-----------------------------------------
.. doxygenclass:: imebra::TransformHighBitDifferentColorSpacesError
   :members:

StreamEOFError
--------------
.. doxygenclass:: imebra::StreamEOFError
   :members:

StreamJpegTagInStreamError
--------------------------
.. doxygenclass:: imebra::StreamJpegTagInStreamError
   :members:

ModalityVOILUTError
-------------------
.. doxygenclass:: imebra::ModalityVOILUTError
   :members:

DicomCodecError
---------------
.. doxygenclass:: imebra::DicomCodecError
   :members:

DicomCodecDepthLimitReachedError
--------------------------------
.. doxygenclass:: imebra::DicomCodecDepthLimitReachedError
   :members:

JpegCodecError
--------------
.. doxygenclass:: imebra::JpegCodecError
   :members:

JpegCodecCannotHandleSyntaxError
--------------------------------
.. doxygenclass:: imebra::JpegCodecCannotHandleSyntaxError
   :members:

ImebraBadAlloc
--------------
.. doxygenclass:: imebra::ImebraBadAlloc
   :members:

MemoryError
-----------
.. doxygenclass:: imebra::MemoryError
   :members:

MemorySizeError
---------------
.. doxygenclass:: imebra::MemorySizeError
   :members:

LutError
--------
.. doxygenclass:: imebra::LutError
   :members:

LutCorruptedError
-----------------
.. doxygenclass:: imebra::LutCorruptedError
   :members:

