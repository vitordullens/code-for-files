#include <iostream>
#include <bits/stdc++.h>
#include "compactstorage.h"

using namespace std;

int main(int argc, char** argv)
{
  CompactStorage storage;

  // Write data
  storage.writeBool(true);
  storage.writeBool(false);
  storage.writeBool(true);
  storage.writeBool(false);
  storage.writeBool(true);
  storage.writeBool(false);
	
  // get content
	fstream fd;
  fd.open("out.txt", ios::out | ios::binary);
  storage.dump(&fd);
  fd.close();

  // Display the compacted data
  storage.dump();
  
  // Read it again
  storage.reset();
  cout << storage.readBool() << endl;
  cout << storage.readBool() << endl;
  return 0;
}

