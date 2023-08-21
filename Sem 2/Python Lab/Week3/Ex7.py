notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
note = input("Enter Note : ")
noteind  = notes.index(note)
length = len(notes) - 1
print(notes[noteind],end = ' ')
if(noteind < length) :
    noteind += 2
    print(notes[noteind],end = ' ')
else :
    noteind = abs(length - noteind + 1)
    print(notes[noteind],end = ' ')
if(noteind < length) :
    noteind += 2
    print(notes[noteind], end = ' ')
else :
    noteind = abs(length - noteind)
    print(notes[noteind], end = ' ')
if(noteind < length) :
    noteind += 1
    print(notes[noteind],end = ' ')
else :
    noteind = abs(length - noteind)
    print(notes[noteind],end = ' ')
if(noteind < length) :
    noteind += 2
    print(notes[noteind], end = ' ')
else :
    noteind = abs(length - noteind + 1)
    print(notes[noteind],end = ' ')
if(noteind < length) :
    noteind += 2
    print(notes[noteind],end = ' ')
else :
    noteind = abs(length - noteind + 1)
    print(notes[noteind],end = ' ')
if(noteind < length) :
    noteind += 2
    print(notes[noteind], end = ' ')
else :
    noteind = abs(length - noteind + 1)
    print(notes[noteind],end = ' ')
