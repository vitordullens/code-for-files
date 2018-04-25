import re

cell = r"<td>(\d{4}),(\d{4})</td>" 
name = r"<td>(\w+)</td>"
tag = (0,0)
tagName = ""
out = {}
with open("DICOM_Tags.html") as file:
    for line in file:
        m = re.search(cell, line)
        if m != None:
            (a, b) = m.groups()
            tag = (a,b)
        else:
            p = re.search(name, line)
            if p != None:
                tagName = p.groups(0)[0]
                out[tag] = tagName

f = open("tags.txt", 'w')
for k in out.keys():
    f.write('{},{},{}\n'.format(int(k[0]), int(k[1]), str(out[k])))
f.close()