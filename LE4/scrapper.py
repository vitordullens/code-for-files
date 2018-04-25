import re

cell = r'<td class="setColor">\((\d{4}),(\d{4})\)</td><td class="setColor">([\w\s]+)</td><td class="setColor">([\w\s]+)</td>' 
tag = (0,0)
tagName = ""
out = {}
with open("DICOM_Tags.html") as file:
    for line in file:
        m = re.search(cell, line)
        if m != None:
            (a, b) = (m.group(1), m.group(2))
            tag = (a,b)
            tagName = m.group(4)
            out[tag] = tagName

f = open("tags.txt", 'w')
for k in out.keys():
    f.write('{},{},{}\n'.format(int(k[0]), int(k[1]), str(out[k])))
f.close()
