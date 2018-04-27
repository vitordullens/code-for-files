DICOM dataSet & tags classes
============================

This section describes the classes and methods responsible for retrieving and setting the information that composes the
DICOM structure, represented by the class :cpp:class:`imebra::DataSet`.

Each individual piece of information is stored into a tag (see :cpp:class:`imebra::Tag`) inside the DICOM structure.


DataSet
-------
.. doxygenclass:: imebra::DataSet
   :members:

Tag
---
.. doxygenclass:: imebra::Tag
   :members:

TagId
-----
.. doxygenclass:: imebra::TagId
   :members:

ReadingDataHandler
------------------
.. doxygenclass:: imebra::ReadingDataHandler
   :members:

ReadingDataHandlerNumeric
-------------------------
.. doxygenclass:: imebra::ReadingDataHandlerNumeric
   :members:

WritingDataHandler
------------------
.. doxygenclass:: imebra::WritingDataHandler
   :members:

WritingDataHandlerNumeric
-------------------------
.. doxygenclass:: imebra::WritingDataHandlerNumeric
   :members:
