Introduction
============

Imebra is a C++ library able to parse and build DICOM files (including DICOMDIR
files). It also supplies the necessary codecs to encode and decode the images
embedded in the DICOM files.

When Imebra reads a file then it inserts the file content into a Dicom structure 
in memory managed by the :cpp:class:`imebra::DataSet` class.

Other functions in the dataset allow the application to read or write into
the DICOM tags, or to store new images into the dataSet.

You can get Imebra from https://imebra.com

Before committing to the usage of Imebra, please read the :ref:`REQUIREMENTS` that the library
fullfills as well as the :ref:`RISKS` that the usage of the library introduces.

