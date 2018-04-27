Loading & saving classes
========================

The classes described in this section are used to load and store DICOM structures
(represented by the class :cpp:class:`imebra::DataSet`).

The easiest way to load and store an :cpp:class:`imebra::DataSet` object is by using the static methods
of the :cpp:class:`imebra::CodecFactory` class.


BaseStreamInput
---------------
.. doxygenclass:: imebra::BaseStreamInput
   :members:

BaseStreamOutput
----------------
.. doxygenclass:: imebra::BaseStreamOutput
   :members:

CodecFactory
------------
.. doxygenclass:: imebra::CodecFactory
   :members:

FileStreamInput
---------------
.. doxygenclass:: imebra::FileStreamInput
   :members:

FileStreamOutput
----------------
.. doxygenclass:: imebra::FileStreamOutput
   :members:

MemoryStreamInput
-----------------
.. doxygenclass:: imebra::MemoryStreamInput
   :members:

MemoryStreamOutput
------------------
.. doxygenclass:: imebra::MemoryStreamOutput
   :members:

StreamReader
------------
.. doxygenclass:: imebra::StreamReader
   :members:

StreamWriter
------------
.. doxygenclass:: imebra::StreamWriter
   :members:
