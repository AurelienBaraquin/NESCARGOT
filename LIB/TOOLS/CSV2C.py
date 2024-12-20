#!/usr/bin/python3

import sys
import csv
import os

if len(sys.argv) != 2:
  print("Usage: CSV2C.py <filename.csv>")
  sys.exit(1)

filename = sys.argv[1]
newname = filename[0:-4] + ".c"
newname2 = os.path.basename(filename)
newname2 = newname2[0:-4]

with open(filename, 'r') as oldfile:
  reader = csv.reader(oldfile)
  your_list = list(reader)

newfile = open(newname, 'w')  # warning, this may overwrite old file !
newfile.write("unsigned char " + newname2 + "[]={\n")

rows = len(your_list)
columns = len(your_list[0])

for i in range (0, rows):
	for j in range (0, columns):
		newfile.write(your_list[i][j] + ",")
	newfile.write("\n")

z = newfile.tell()
z = z - 3
newfile.seek(z)

newfile.write("\n};\n")

print("Done.")
oldfile.close
newfile.close
