# This file was created specifically to read the tags from DICOM_Tags.html
# Because there are many tags in DICOM Standard.
# by Gguidini. Version 3.0

import re

cell = r'<td class="setColor">\((\d{4}),(\d{4})\)</td><td class="setColor">([\w\s]+)</td><td class="setColor">([\w\s]+)</td>' 
alternativeCell = r'<td>\((\d{4}),(\d{4})\)</td><td>([\w\s]+)</td><td>([\w\s]+)</td>'
tag = (0,0)
tagName = ""
VR = ""
out = {}
with open("DICOM_Tags.html") as file:
    for line in file:
        m = re.search(cell, line)
        p = re.search(alternativeCell, line)
        if m != None:
            (a, b) = (m.group(1), m.group(2))
            tag = (a,b)
            VR = m.group(3)
            tagName = m.group(4)
            tagName = tagName.replace(" ", '')
            out[tag] = (VR, tagName)
        elif p != None:
            (a, b) = (p.group(1), p.group(2))
            tag = (a,b)
            VR = p.group(3)
            tagName = p.group(4)
            tagName = tagName.replace(" ", '')
            out[tag] = (VR, tagName)

f = open("tags.txt", 'w')
for k in out.keys():
    f.write('{},{},{},{}\n'.format(int(k[0]), int(k[1]), (out[k])[0], (out[k])[1]))
f.close()
